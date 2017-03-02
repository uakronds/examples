#include <cstdlib>
#include <ctime>
#include <iostream>

#include "avl_tree.hpp"

int main() {

  srand(time(0));

  AVLTree<int>* avl = new AVLTree<int>;
  /*
  for (int i = 0; i < 16; ++i)
    avl->insert(rand() % 100);
  */

  for (auto x : { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }) 
    avl->insert(x);

  std::cout << avl->serialize() << std::endl;

}
