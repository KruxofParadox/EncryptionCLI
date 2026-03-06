#include "../include/functions.h"
#include <iostream>

int main(int argc, char* argv[]) {
  std::vector<std::string> filecontents;

  switch (argc) {
    case 1:
      printUsage();
      break;
    case 2:
      std::cout << "---No current functionality---" << std::endl;
      break;
    case 3:
      // validate input and parse isntructions
      break;
  }

  if (argc == 2) {
    filecontents = readFromFile(argv[1]);
  }
  
  for (auto line: filecontents)
    std::cout << line << std::endl;
}