#include "../include/functions.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

void printUsage() {
      std::cout << "usage: ecrypt [-v | --version] [-h | --help]" << std::endl;
      std::cout << "              <command> [<args>]" << std::endl;
      std::cout << std::endl;
      std::cout << "Encrypt a file" << std::endl;
      std::cout << "\t[-e | encrypt] <file>                  \t\tEncrypt a file with default encryption settings" << std::endl;
      std::cout << "\t[-d | decrypt] <decryption-type> <file>\t\tDecrypt a file with the given decryption type" << std::endl;
}

void getUserFunction(int numArguments, char* arguments[], std::vector<std::string>* filecontents) {
      if (arguments[1] == "-e" || "encrypt") {
        if (checkValidFile(arguments[2])) {          
          *filecontents = readFromFile(arguments[2]);
        }
      }

}

bool checkFileExtension(std::string filename) {
  int extensionIndex = 0;
  for (int i = 0; i < filename.length(); i++) {
    if (filename[i] == '.')
      extensionIndex = i;
  }

  std::string extensionType = filename.substr(extensionIndex+1);
  
  if (extensionType != "txt")
    return false;
  
    return true;
}

bool checkValidFile(std::string filename) {
  std::ifstream file;
  if (!checkFileExtension(filename)) { 
    std::cerr << "Error: File is not a text file" << std::endl;
    return false;
  }

  file.open(filename);

  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    if (file.fail())
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