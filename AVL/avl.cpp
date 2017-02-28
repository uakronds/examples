#include <iostream>

#include "avl_tree.hpp"

int main() {
  AVLTree<int>* avl = new AVLTree<int>;

  avl->insert(10);
  avl->insert(5);
  avl->insert(20);
  avl->insert(50);

  std::cout << avl->serialize() << std::endl;
}
