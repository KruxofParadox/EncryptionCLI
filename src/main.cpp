#include "../include/functions.h"
#include <iostream>

int main(int argc, char* argv[]) {
  std::vector<std::string> filecontents;

  if (argc == 2) {
    filecontents = readFromFile(argv[1]);
  }

  for (auto line: filecontents)
    std::cout << line << std::endl;
}