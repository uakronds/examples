#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <algorithm>
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
public:
  AVLNode<T>* root = nullptr;

  void insert(AVLNode<T>*, T);
  void update_height(AVLNode<T>*);
  int  check_balance(AVLNode<T>*);
  void left_rotate(AVLNode<T>*);
  void right_rotate(AVLNode<T>*);
  void double_left_rotate(AVLNode<T>*);
  void double_right_rotate(AVLNode<T>*);
  void serialize(AVLNode<T>*, std::stringstream&);
public:
  AVLTree() {}
  ~AVLTree() {}

  void insert(T);

  std::string serialize(); // helper that calls a recursive
};

template <class T>
void AVLTree<T>::update_height(AVLNode<T>* n) {
  if (!n)
    return;

  n->height = 1 + std::max(n->left ? n->left->height : -1, n->right ? n->right->height : -1);
}

template <class T>
int AVLTree<T>::check_balance(AVLNode<T>* n) {
  return (n->left ? n->left->height : -1) - (n->right ? n->right->height : -1);
}

template <class T>
void AVLTree<T>::left_rotate(AVLNode<T>* n) {
  AVLNode<T>* p = n;
  AVLNode<T>* m = n->right;
  p->right = m->left;

  if (m->left)
    m->left->parent = p;

  m->parent = n->parent;

  m->left = p;
  p->parent = m;

  if (!m->parent)
    root = m;
  else
    m->data < m->parent->data ? m->parent->left = m : m->parent->right = m;

  update_height(p);
  update_height(m);
}

template <class T>
void AVLTree<T>::right_rotate(AVLNode<T>* n) {
  AVLNode<T>* p = n;
  AVLNode<T>* m = n->left;
  p->left = m->right;
  if (m->right)
    m->right->parent = p;

  m->parent = n->parent;

  m->right = p;
  p->parent = m;

  if (!m->parent)
    root = m;
  else
    m->data < m->parent->data ? m->parent->left = m : m->parent->right = m;

  update_height(p);
  update_height(m);
}

template <class T>
void AVLTree<T>::double_left_rotate(AVLNode<T>* n) {
  right_rotate(n->right);
  left_rotate(n);
}

template <class T>
void AVLTree<T>::double_right_rotate(AVLNode<T>* n) {
  left_rotate(n->left);
  right_rotate(n);
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
  update_height(n);
  int bf = check_balance(n);
  if (bf < -1) {
   if (check_balance(n->right) > 0) {
      double_left_rotate(n);
   } else {
     left_rotate(n);
   }
  } else if (bf > 1) {
    if (check_balance(n->left) < 0) {
      double_right_rotate(n);
    } else {
      right_rotate(n);
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

  s << "[" << n->data << "|" << n->height << "] ";
  serialize(n->left, s);
  serialize(n->right, s);
}
#endif
