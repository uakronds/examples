#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <iomanip>
#include <map>

class Graph {
private:

  size_t node_count = 0;
  char* node_names;
  int* adj_mat; // this is a 1d array that acts like a 2d array
  std::map<char, size_t> node_locations;

  size_t index(size_t row, size_t col) { return (row * node_count) + col; }
 
public:

  Graph(size_t);
  ~Graph();

  void insert_nodes(std::initializer_list<char> nodes);
  void display();
};

Graph::Graph(size_t size) : node_names(new char[size]), node_count(size), adj_mat(new int[size*size]) {}
Graph::~Graph() {
  delete [] node_names;
  delete [] adj_mat;
}

void Graph::insert_nodes(std::initializer_list<char> nodes) {
  size_t location = 0;
  for (char x : nodes) {
    node_names[location] = x;
    node_locations.insert(std::pair<char, size_t>(x, location++));
  }
}

void Graph::display() {
  adj_mat[index(node_locations['G'], node_locations['B'])] = 3;
  adj_mat[index(node_locations['B'], node_locations['G'])] = 3;

  // list the nodes across the top
  std::cout << "    ";
  for (int i = 0; i < node_count; ++i)
    std::cout << std::setw(4) << node_names[i];

  std::cout << std::endl;

  for (int row = 0; row < node_count; ++row) {
    std::cout << std::setw(4) << node_names[row];
    for (int col = 0; col < node_count; ++col) {
      std::cout << std::setw(4) << adj_mat[index(row, col)]; 
    }
    std::cout << std::endl;
  } 
}
#endif
