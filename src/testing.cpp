#include "../include/utils.h"
#include <vector>
#include <iostream>
#include <string>

int main() {
  std::vector<std::string> word = {"zzzz"};
  int key = 3;
  // int c = 'c';
  // std::cout << "Value of c: " << c << std::endl;
  // std::cout << std::endl; 
  // std::cout << "Value of z mod 122: " << 'z'%122 << std::endl;
  // int swap = 'z'%122 + 3 + 96;
  // std::cout << "Value of z mod 122 + key: " << swap << std::endl;
  

  runCaesarCipher(&word, key);

  for (auto item: word) {
    std::cout << item << std::endl;
  }
}