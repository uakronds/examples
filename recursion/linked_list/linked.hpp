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
  void remove(LNode<T>*);
  void rec_display(LNode<T>*);
  LNode<T>* find_tail(LNode<T>*);
  LNode<T>* rec_reverse(LNode<T>*);

public:
  LList() {}
  LList(LList&);
  ~LList() { clear(); }

  void insert(T t);
  void append(T t);
  void clear();
  void display();
  void reverse();

};

template <class T>
LNode<T>* LList<T>::rec_reverse(LNode<T>* ln) {
  return ln->next ? (rec_reverse(ln->next)->next = ln) : ln;
}

template <class T>
void LList<T>::reverse() {
  if (head == tail)
    return;

  LNode<T>* temp = tail;
  tail = rec_reverse(head);
  head = temp;
  tail->next = nullptr;
}

template <class T>
LList<T>::LList(LList& ll) {
  head = copy(ll.head);
  tail = find_tail(head);
}

template <class T>
LNode<T>* LList<T>::find_tail(LNode<T>* ll) {
  if(!ll)
    return nullptr;

  if(!ll->next)
    return ll;

  return find_tail(ll->next);
}

template <class T>
LNode<T>* LList<T>::copy(LNode<T>* ln) {
  if (!ln)
    return nullptr;

  return new LNode<T>(ln->data, copy(ln->next));
}

template <class T>
void LList<T>::insert(T t) {
  head = new LNode<T>(t, head);
  tail = ( tail ? tail : head );
}

template <class T>
void LList<T>::append(T t) {
  tail = ( tail ? new LNode<T>(tail, t) : new LNode<T>(t) );
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

// helper function for display
template <class T>
void LList<T>::display() {
  rec_display(head);
  std::cout << std::endl;
}

template <class T>
void LList<T>::rec_display(LNode<T>* ln) {
  if (!ln)
    return;

  std::cout << "[" << ln->data << "]";
  rec_display(ln->next);
}

#endif
