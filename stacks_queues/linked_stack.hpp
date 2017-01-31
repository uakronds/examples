/*
  Linked List implementation of a stack
  LIFO
  pop, push, peek, is_empty, clear
 */

#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include <cassert>

// the linked list node struct
// templated
template <class T>
struct Linked_node {
  T data;
  Linked_node* next = nullptr;

  Linked_node(T t) : data(t) {}
  Linked_node(T t, Linked_node* ln) : data(t), next(ln) {} 
};

// the Linked_stack class utilizing the Stack_node class

template <class T>
class Linked_stack {
private:
  Linked_node<T>* top = nullptr;

public:
  ~Linked_stack() { clear(); }

  void clear() { while(top) pop(); }
  void pop();
  void push(T t);
  T peek() { return top->data; }
  bool is_empty() { return !top; }
};

template <class T>
void Linked_stack<T>::pop() {
  if (!top)
    return;

  Linked_node<T>* temp = top;
  top = top->next;
  delete temp;
}

template <class T>
void Linked_stack<T>::push(T t) {
  top = new Linked_node<T>(t, top);
}
#endif
