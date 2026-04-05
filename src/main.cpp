#include "../include/utils.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
  std::vector<std::string> filecontents;

  getFunction(argc, argv, &filecontents);
}