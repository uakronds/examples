/*
  Utilizing the different stacks and queues we write in class
 */

#include <iostream>
#include <string>
#include "linked_stack.hpp"
#include "array_queue.hpp"

template <class T>
void reverse(std::initializer_list<T> li) {
  
  Linked_stack<T> stack;
  
  for (auto x : li) {
    std::cout << "[" << x << "]";
    stack.push(x);
  }
  std::cout << std::endl;
  while(!stack.is_empty()) {
    std::cout << "[" << stack.peek() << "]";
    stack.pop();  
  }
  std::cout << std::endl;
}

int main() {

  reverse({ 1, 2, 3, 4, 5 });
  reverse({"tony", "is", "awesome"});
  reverse({"testing", 34});
}
