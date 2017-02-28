#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>
#include <string>
#include <sstream>

template <class T>
struct AVLNode {
  T data;
  int height = 0;
  AVLNode<T>* left = nullptr, * right = nullptr, * parent = nullptr;

  AVLNode(T t) : data(t) {}
  AVLNode(T t, AVLNode<T>* p) : data(t), parent(p) {}
};

template <class T>
class AVLTree {
private:
  AVLNode<T>* root = nullptr;

  void insert(AVLNode<T>*, T);
  void left_rotate(AVLNode<T>*);
  void serialize(AVLNode<T>*, std::stringstream&);
public:
  AVLTree() {}
  ~AVLTree() {}

  void insert(T);

  std::string serialize(); // helper that calls a recursive
};

template <class T>
void AVLTree<T>::left_rotate(AVLNode<T>* n) {
  AVLNode<T>* p = n;
  AVLNode<T>* m = n->right;
  p->right = m->left;
  m->left->parent = p;

  m->parent = n->parent;

  m->left = p;
  p->parent = m;

  if (!m->parent)
    root = m;
  else
    m->data < m->parent->data ? m->parent->left = m : m->parent->right = m;
}

template <class T>
void AVLTree<T>::insert(T t) {
  if (!root) {
    root = new AVLNode<T>(t); 
    return;
  }
  insert(root, t); // recursive function call
}

template <class T>
void AVLTree<T>::insert(AVLNode<T>* n, T t) {
  if (n->data == t)
    return;

  if (n->data > t) {
    if (n->left) {
      insert(n->left, t);
    } else {
      n->left = new AVLNode<T>(t, n);
    }
  } else { 
    if (n->right) {
      insert(n->right, t);
    } else {
      n->right = new AVLNode<T>(t, n);
    }
  }

} 
 

template <class T>
std::string AVLTree<T>::serialize() {
  std::stringstream ret;
  serialize(root, ret);
  return ret.str();
}

template <class T>
void AVLTree<T>::serialize(AVLNode<T>* n, std::stringstream& s) {
  if (!n) {
    s << "/ ";
    return;
  }

  s << n->data << " ";
  serialize(n->left, s);
  serialize(n->right, s);
}
#endif
