#ifndef LINKED_HPP
#define LINKED_HPP

/*
  linked list recursion class
*/

#include <iostream>

template <class T>
struct LNode {
  T data;
  LNode* next = nullptr;

  LNode(T t) : data(t) {}
  LNode(T t, LNode* ln) : data(t), next(ln) {}
  LNode(LNode* ln, T t) : data(t) { ln->next = this; }
};

template <class T>
class LList {
private:
  LNode<T>* head = nullptr, * tail = nullptr;
  // copy a linked list from a beginning node, and return a pointer to the beginning of the copy
  LNode<T>* copy(LNode<T>*);

public:
  // LList() {}
  ~LList() { clear(); }

  void insert(T t);
  void append(T t);
  void clear();
  void display();

};

template <class T>
void LList<T>::insert(T t) {
  head = new LNode(t, head);
  tail = ( tail ? tail : head );
}

template <class T>
void LList<T>::append(T t) {
  tail = ( tail ? new LNode(tail, t) : new LNode(t) );
  head = ( head ? head : tail );
}

template <class T>
void LList<T>::clear() {
  remove(head);
}

template <class T>
void LList<T>::remove(LNode<T>* start) {
  if (!start)
    return;

  remove(start->next);
  delete start;
}

#endif
