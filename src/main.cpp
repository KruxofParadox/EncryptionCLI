#include "../include/utils.h"
#include <iostream>

int main(int argc, char* argv[]) {
  std::vector<std::string> filecontents;

  switch (argc) {
    case 1:
      printUsage();
      printHelp();
      break;
    case 2:
      std::cout << "---No current functionality---" << std::endl;
      break;
    default:
      getUserFunction(argc, argv, &filecontents);
      break;
  }
  
  int userContinue;
  std::cout << "Press \'Enter\' to continue: ";
  std::cin >> userContinue;
  for (auto line: filecontents)
    std::cout << line << std::endl;
}