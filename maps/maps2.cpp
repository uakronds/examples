#include <map> // for maps
#include <iostream>
#include <string>
/*

  char -> struct [freq and code]

 */

struct letter {
  int freq = 0;
  std::string code;
};

int main() {
  
  std::map<char, letter> freqs;
  std::map<char, letter>::iterator it;

  // ask the user for input
  // add the first letter of the input to the map and count how many times this has happened
  
  std::string input;
  
  std::cout << "enter a letter: ";
  std::cin >> input;
  
  while(input != "q") {
    it = freqs.find(input[0]);
    // is there
    if (it != freqs.end()) {
      it->second.freq++;
      it->second.code += "o";
    } else { // isn't there
      freqs[input[0]].freq = 1;
      freqs[input[0]].code = "o";
    }

    std::cout << "enter a letter: ";
    std::cin >> input;

  }
  
  for (auto x : freqs) {
    std::cout << x.first << ": " << x.second.freq << " | " << x.second.code << std::endl;
  }
}
