#include "../include/utils.h"
#include <vector>
#include <iostream>
#include <string>

void testRunCaesarCipher();
void testSplitString();

int main() {

  testSplitString();

  
}

void testRunCaesarCipher() {
  std::vector<std::string> word = {"hello world", "this is a test"};
  int key = 3;

  runCaesarCipher(&word, key);

  for (auto item: word)
    std::cout << item << std::endl;
}

void testSplitString() {
  std::vector<std::string> test = splitString("caesar 3");

  for (auto item: test)
    std::cout << item << std::endl;
}