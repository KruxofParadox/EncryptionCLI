#include "../include/functions.h"
#include <fstream>
#include <iostream>

void printUsage() {
      std::cout << "usage: ecrypt [-v | --version] [-h | --help]" << std::endl;
      std::cout << "              <command> [<args>]" << std::endl;
      std::cout << std::endl;
      std::cout << "Encrypt a file" << std::endl;
      std::cout << "\t[-e | encrypt] <file>                  \t\tEncrypt a file with default encryption settings" << std::endl;
      std::cout << "\t[-d | decrypt] <decryption-type> <file>\t\tDecrypt a file with the given decryption type" << std::endl;
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