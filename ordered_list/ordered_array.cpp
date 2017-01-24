/*
  CS316
  Deeter
  An ordered list of integers
  For simplicity an integer can only be stored in the list once
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

class Ordered_list {
private:
  size_t _size; // the available space for elements
  size_t _count; // the elements that are actually utilized
  int* my_data; // the array of elements

  bool search(int, size_t&);
  bool search(int, int, int, size_t&); // the recursive binary search
  void insert(int, size_t); // insert from a specific location
public:
  Ordered_list(size_t size); // constructor
  ~Ordered_list(); // destructor

  // the following describe the ADT
  bool search(int); // the helper function that starts the recursive binary search
  bool insert(int); // insert an integer into the list
  bool remove(int); // remove an integer from the list
  bool is_empty(); // returns if the list is empty
  void clear(); // clears the list
  void display(); // display the list
};

Ordered_list::Ordered_list(size_t size) : _size(size), _count(0) {
  my_data = new int[size];
}

Ordered_list::~Ordered_list() {
  delete [] my_data;
}

bool Ordered_list::search(int find_this) {
  if (_count < 1)
    return false;

  //call the overloaded search function
  size_t temp;
  return search(find_this, temp) != false;
}

bool Ordered_list::search(int find_this, size_t& location) {
  if (_count < 1) {
    location = 0; // the list is empty so we set the location to 0
    return false;
  }
  // recursively search using binary search
  return search(0, _count - 1, find_this, location) != false;
}

bool Ordered_list::search(int start, int end, int find_this, size_t& location) {
  if (end < start)  
    return false;

  location = (start + end) / 2;
  if (my_data[location] == find_this)
    return true;
  if (my_data[location] > find_this)
    return location == 0 ? false : search(start, location - 1, find_this, location);
  return search(location + 1, end, find_this, location);
}

bool Ordered_list::insert(int element) {
  // test to see if the list is full
  assert(_size > _count);

  size_t location = 0;
  if (search(element, location) == false) {
    if (element < my_data[location])
      insert(element, location);
    else
      insert(element, location + 1);
  }
  return true;
}

void Ordered_list::insert(int element, size_t location) {
  for(size_t i = _count; i > location; --i) {
    my_data[i] = my_data[i - 1]; 
  }
  my_data[location] = element;
  ++_count;
}

void Ordered_list::display() {
  for (int i = 0; i < _count; ++i) {
    std::cout << "[" << my_data[i] << "]";
  }
  std::cout << std::endl;
}

void Ordered_list::clear() {
  _count = 0;
}

bool Ordered_list::is_empty() {
  return _count == 0;
}

int main() {
  // seed the random
  srand(time(0));

  Ordered_list list(100);
  for (int i = 0; i < 10; ++i)
    list.insert(rand() % 100);

  list.display();

  list.clear();
  std::cout << "This list ... is " << ( list.is_empty() ? "" : "not " ) << "clear!" << std::endl;
  list.display();
}
