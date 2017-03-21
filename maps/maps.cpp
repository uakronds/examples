#include <map> // for maps
#include <iostream>
#include <string>
/*

  char -> struct [freq and code]

 */

int main() {
  
  std::map<char, int> freqs;
  std::map<char, int>::iterator it;

  // ask the user for input
  // add the first letter of the input to the map and count how many times this has happened
  
  std::string input;
  
  std::cout << "enter a letter: ";
  std::cin >> input;
  
  while(input != "q") {
    it = freqs.find(input[0]);
    // is there
    if (it != freqs.end()) {
      it->second++;
    } else { // isn't there
      freqs[input[0]] = 1;
    }

    std::cout << "enter a letter: ";
    std::cin >> input;

  }
  
  for (auto x : freqs) {
    std::cout << x.first << ": " << x.second << std::endl;
  }
}
