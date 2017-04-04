/*
  quicksort example
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

// swap function that takes a vector and two indeces
void swap(std::vector<int>& vec, int a, int b) {
  int temp = vec[a];
  vec[a] = vec[b];
  vec[b] = temp;
}

// a partition function that returns the pivot position
size_t partition(std::vector<int>& vec, int start, int end, int pivot_value) {
  do {
    // move the left pointer
    while(vec[++start] < pivot_value);
    // move the right pointer
    while(start < end && vec[--end] > pivot_value);
    if (start != end)
      swap(vec, start, end);
  } while (start < end); // a long as we havent found the correct position for the pivot
  return start; // return the pivot position
} 

void quicksort(std::vector<int>& vec, int start, int end) {
  
  if (start >= end)
    return;

  int mid = (start + end) / 2;
  swap(vec, mid, end);
  size_t part = partition(vec, start - 1, end, vec[end]);
  
  swap(vec, part, end);
  quicksort(vec, start, part - 1);
  quicksort(vec, part + 1, end);
}
