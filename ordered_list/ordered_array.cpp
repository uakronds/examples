/*
  CS316
  Deeter
  An ordered list of integers
  For simplicity an integer can only be stored in the list once
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

class Ordered_list {
private:
  size_t _size; // the available space for elements
  size_t _count; // the elements that are actually utilized
  int* my_data; // the array of elements

  int search(int, int, int); // the recursive binary search

public:
  Ordered_list(size_t size); // constructor
  ~Ordered_list(); // destructor

  // the following describe the ADT
  bool search(int); // the helper function that starts the recursive binary search
  bool insert(int); // insert an integer into the list
  bool remove(int); // remove an integer from the list
  bool is_empty(); // returns if the list is empty
  void clear(); // clears the list
};

Ordered_list::Ordered_list(size_t size) : _size(size), _count(0) {
  my_data = new int(size);
}

Ordered_list::~Ordered_list() {
    delete [] my_data;
}

bool Ordered_list::search(int find_this) {
  if (_count < 1)
    return false;

  // recursively search using binary search
  return search(0, _count - 1, find_this) == -1;
}

int Ordered_list::search(int start, int end, int find_this) {
  if (end < start)
    return -1;

  int mid = (start + end) / 2;
  if (my_data[mid] == find_this)
    return mid;
  if (my_data[mid] > find_this)
    return search(start, mid - 1, find_this);
  return search(mid + 1, end, find_this);
}

int main() {
  // seed the random
  srand(time(0));

  Ordered_list list(100);
}
