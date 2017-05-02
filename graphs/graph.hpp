#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
#include <queue>
#include <string>
#include <limits>

class Graph {
private:

  bool directed = false;
  size_t node_count = 0; // the number of nodes in the graph
  char* node_names; // an arracy of node labels
  int* adj_mat; // this is a 1d array that acts like a 2d array
  std::map<char, size_t> node_locations; // this maps the character to the index in node names

  size_t index(size_t row, size_t col) { return (row * node_count) + col; } // converts a row/col into the 1d array index
 
public:

  Graph(size_t, bool);
  ~Graph();

  void insert_nodes(std::initializer_list<char> nodes); // insert the nodes into the graph using an intitializer list 
  void insert_edge(char, char, int);
  void display(); // display the graph to the screen

  void dijkstra(char, bool);
};

Graph::Graph(size_t size, bool d = false) : node_names(new char[size]), node_count(size), 
			    directed(d), adj_mat(new int[size*size]) {}
Graph::~Graph() {
  delete [] node_names;
  delete [] adj_mat;
}

void Graph::insert_nodes(std::initializer_list<char> nodes) {
  size_t location = 0;
  for (char x : nodes) { // range-based for loop
    node_names[location] = x; // set the next location in the node_names array to the current label
    node_locations.insert(std::pair<char, size_t>(x, location++)); // add the map pair
  }
}

void Graph::insert_edge(char from, char to, int weight) {
  adj_mat[index(node_locations[from], node_locations[to])] = weight;
  if (!directed)
    adj_mat[index(node_locations[to], node_locations[from])] = weight;
}

void Graph::dijkstra(char start, bool debug = false) {
  
  struct DNode {
    int index; // the index in the node_names array
    std::string path;
    char from;
    int cost = std::numeric_limits<int>::max();
  };
  
  // the array of DNodes
  DNode dnodes[node_count];

  // fill the array with the correct information
  // init step for dijkstra
  for (int i = 0; i < node_count; ++i) {
    dnodes[i].index = i;
    dnodes[i].from = '-';
    size_t start_index = node_locations[start];
    if (i == start_index) { // the node is the starting node
      dnodes[i].cost = 0;
    } else if (adj_mat[index(start_index, dnodes[i].index)] > 0) {
      dnodes[i].cost = adj_mat[index(start_index, dnodes[i].index)];
      dnodes[i].from = start;
      dnodes[i].path = start;
    }
  }

  auto costs = [&]() {

    for (int i = 0; i < node_count; ++i) {
      std::stringstream x;
      x << node_names[dnodes[i].index] << ": " << dnodes[i].cost << " :" << dnodes[i].from << "   ";
      std::cout << std::setw(13) << x.str();
    }
    std::cout << std::endl;
  }; 
  
  auto compare = [&](DNode* left, DNode* right) { return left->cost > right->cost; };
  std::priority_queue<DNode*, std::vector<DNode*>, decltype(compare) > pq(compare);

  // enqueue all of the DNodes
  for (int i = 0; i < node_count; ++i)
    pq.push(&dnodes[i]);

  while(!pq.empty()) {
    // dequeue the node pointer
    DNode* current = pq.top();
    pq.pop();

    // relax the edges
    // d[n] > d[current] + w(current, n)
    for (int i = 0; i < node_count; ++i) {
      int temp_index = index(current->index, dnodes[i].index);
      if (adj_mat[temp_index] && dnodes[i].cost > current->cost + adj_mat[temp_index]) {
	dnodes[i].cost = current->cost + adj_mat[temp_index];
	dnodes[i].from = node_names[current->index];
	dnodes[i].path = current->path + " " + node_names[current->index];
      }
    }
    if (debug) {
      std::cout << node_names[current->index] << " --> ";
      costs();
    }
  }

  // display the paths
  for (int i = 0; i < node_count; ++i) {
    std::cout << node_names[dnodes[i].index] << ": " << std::setw(15) << dnodes[i].path << "  " << dnodes[i].cost << std::endl;
  }


}

void Graph::display() {

  // list the nodes across the top
  std::cout << "    ";
  for (int i = 0; i < node_count; ++i)
    std::cout << std::setw(4) << node_names[i];
  std::cout << std::endl;

  // list each row of the graph using the index function to find the location
  for (int row = 0; row < node_count; ++row) {
    std::cout << std::setw(4) << node_names[row];
    for (int col = 0; col < node_count; ++col) {
      std::cout << std::setw(4) << adj_mat[index(row, col)]; 
    }
    std::cout << std::endl;
  } 
}

#endif
