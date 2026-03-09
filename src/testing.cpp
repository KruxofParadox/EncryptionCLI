#include "../include/utils.h"
#include <vector>
#include <iostream>
#include <string>

int main() {
  std::vector<std::string> word = {"hello world", "this is a test"};
  int key = 3;

  runCaesarCipher(&word, key);

  for (auto item: word) {
    std::cout << item << std::endl;
  }
}