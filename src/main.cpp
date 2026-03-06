#include "../include/functions.h"
#include <iostream>

int main(int argc, char* argv[]) {
  std::vector<std::string> filecontents;

  

  getUserFunction(argc, argv, &filecontents);

  for (auto line: filecontents)
    std::cout << line << std::endl;
}