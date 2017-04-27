#include <iostream>

#include "graph.hpp"

int main() {


  Graph graph(7);
  
  graph.insert_nodes({ 'C', 'B', 'G', 'A', 'H', 'I', 'F' });
  graph.display();
  
  /*
  graph.insert_edge('C', 'B', 9);
  graph.insert_edge('C', 'F', 2);
  graph.insert_edge('B', 'G', 3);
  graph.insert_edge('B', 'A', 14);
  graph.insert_edge('B', 'F', 10);
  graph.insert_edge('G', 'A', 10);
  graph.insert_edge('G', 'H', 6);
  graph.insert_edge('G', 'I', 4);
  graph.insert_edge('H', 'A', 17);
  graph.insert_edge('H', 'I', 1);
  graph.insert_edge('I', 'F', 7);
  
  graph.print_matrix();

  graph.BFS('A');
  */
}
