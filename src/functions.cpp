#include "../include/functions.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

void printUsage() {
      std::cout << "usage: ecrypt [-v | --version] [-h | --help]" << std::endl;
      std::cout << "              <command> [<args>]" << std::endl;
      std::cout << std::endl;
      std::cout << "Encrypt a file" << std::endl;
      std::cout << "\t[-e | encrypt] <file>                  \t\tEncrypt a file with default encryption settings" << std::endl;
      std::cout << "\t[-d | decrypt] <decryption-type> <file>\t\tDecrypt a file with the given decryption type" << std::endl;
}

void getUserFunction(int numArguments, char* arguments[], std::vector<std::string>* filecontents) {
  switch (numArguments) {
    case 1:
      std::cout << "Print usage";
      break;
    case 3:
      if (arguments[1] == "-e") {
        if (checkFileValid(arguments[2])) {
          *filecontents = readFromFile(arguments[2]);
        }
      }
      break;
  }


}

bool checkFileValid(std::string filename) {
  std::ifstream file;
  // check if file is a text file
    // split string at '.'

  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    std::cerr << strerror(errno) << std::endl;
    return false;
  }


  file.close();
  return true;
}

std::vector<std::string> readFromFile(std::string filename) {
  std::vector<std::string> filedata;
  std::string line;
  std::ifstream file(filename);

  while (std::getline(file, line)) {
    filedata.push_back(line);
  }

  return filedata;
}