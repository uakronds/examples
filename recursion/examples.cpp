/*
  Recursion examples
*/

#include <iostream>
#include <cassert>

// x^y
int exp(int x, int y, int& count) {
  ++count;
  assert(y > -1);

  // base
  if (y == 0)
    return 1;
  
  // recursion
  return x * exp(x, y - 1, count);
}

int dac_exp(int x, int y, int& count) {
    ++count;
  assert(y > -1);

  // base
  if (y == 0)
    return 1;

  int temp = dac_exp(x, y/2, count);
  return temp * temp * (y%2 ? x : 1);
}

int main() {
  
  int count = 0;
  std::cout << "exp(2, 9) = " << exp(2, 9, count);
  std::cout << "     count: " << count << std::endl;

  count = 0;
  std::cout << "dac_exp(2, 9) = " << dac_exp(2, 9, count);
  std::cout << "     count: " << count << std::endl;

  count = 0;
  std::cout << "dac_exp(2, 13) = " << dac_exp(2, 13, count);
  std::cout << "     count: " << count << std::endl;

  count = 0;
  std::cout << "dac_exp(2, 15) = " << dac_exp(2, 15, count);
  std::cout << "     count: " << count << std::endl;

  count = 0;
  std::cout << "dac_exp(2, 16) = " << dac_exp(2, 16, count);
  std::cout << "     count: " << count << std::endl;

}
