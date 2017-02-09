/*
  Recursion examples for linked lists
*/

#include "linked.hpp"

int main() {
  LList<int> x;
  
  for (auto num : { 1, 2, 3, 4, 5 })
    x.insert(num);

  for (auto num : { 0 })
    x.append(num);


  x.display();
  LList<int> y(x);

  y.reverse();
  x.display();
  y.display();
  
}
