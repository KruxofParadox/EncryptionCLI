#include "../include/utils.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
  std::vector<std::string> filecontents;

  switch (argc) {
    case 2:
      std::cout << "---No current functionality---" << std::endl;
      printUsage();
      printHelp();
      break;
    case 3:
      getUserFunction(argc, argv, &filecontents);
      break;
    default: 
      case 1:
      printUsage();
      printHelp();
      break;
  }
  
  std::string userContinue;
  std::cout << "Press \'Enter\' to continue: ";
  std::getline(std::cin, userContinue);
  for (auto line: filecontents)
    std::cout << line << std::endl;
}