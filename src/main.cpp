#include "../include/functions.h"
#include <iostream>

int main(int argc, char* argv[]) {
  std::vector<std::string> filecontents;

  if (argc == 1) {
    std::cout << "usage: ecrypt [-v | --version] [-h | --help]" << std::endl;
    std::cout << "              <command> [<args>]" << std::endl;
    std::cout << std::endl;
    std::cout << "Encrypt a file" << std::endl;
    std::cout << "\t[-e | encrypt] <file>                  \t\tEncrypt a file with default encryption settings" << std::endl;
    std::cout << "\t[-d | decrypt] <decryption-type> <file>\t\tDecrypt a file with the given decryption type" << std::endl;
  }

  if (argc == 2) {
    filecontents = readFromFile(argv[1]);
  }

  for (auto line: filecontents)
    std::cout << line << std::endl;
}