#include "../include/utils.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

void printUsage() {
  std::cout << "usage: ecrypt [-v | --version] [-h | --help]" << std::endl;
  std::cout << "              <command> [<args>]" << std::endl;
  std::cout << std::endl;
}

void printHelp() {
  std::cout << "Encrypt a file" << std::endl;
  std::cout << "\t[-e | encrypt] <file>                  \t\tEncrypt a file with default encryption settings" << std::endl;
  std::cout << "\t[-d | decrypt] <decryption-type> <file>\t\tDecrypt a file with the given decryption type" << std::endl;
  std::cout << std::endl;
}

void getUserFunction(int numArguments, char* arguments[], std::vector<std::string>* filecontents) {
  if (std::strcmp(arguments[1], "-e") || std::strcmp(arguments[1], "encrypt")) {
    if (checkValidFile(arguments[2])) {          
      *filecontents = readFromFile(arguments[2]);
      encryptFile(filecontents);
    }
  }
  else {
    if (determineOptionOrCommand(arguments[1])) {
      std::cerr << "unknown option: " << arguments[1] << std::endl;
      printUsage();         
    }
    else
      std::cerr << "ecrypt: \'" << arguments[1] << "\' is not an ecrypt command. See \'ecrypt --help\'" << std::endl; 
  }
}

int determineOptionOrCommand(std::string argument) {
  if (argument[0] == '-')
    return 1;
  return 0;
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

void encryptFile(std::vector<std::string>* filecontents) {
  std::string userCipher;
  std::cout << "> ";
  std::getline(std::cin, userCipher);
 
  switch (parseUserCipher(userCipher)) {
    case 0:
      // run caesar cipher
      std::cout << "Ran caesar cipher" << std::endl;
      break;
    default: 
      std::cerr << "Error: " << userCipher << " is not a valid cipher" << std::endl;
  }
  
}

std::vector<std::string> splitString(std::string toSplit) {
  std::vector<std::string> split;
  std::string userArgument;
  for (auto letter: toSplit) {
    if (letter == ' ') {
      userArgument = "";
      split.push_back(userArgument);
    }
    userArgument += letter;
  }

  return split;
}

int parseUserCipher(std::string userCipher) {
  std::vector<std::string> userInputs = splitString(userCipher);
  if (userInputs.size() > 2)
    return -1;
    // should be tied in to cipherList
    if (userInputs[0] == "caesar") {
    return 0;
  }
}

void runCaesarCipher(std::vector<std::string>* filecontents, int key) {
  for (auto word: *filecontents) {
    for (auto i = 0; i < word.length(); i++) {
      if (word[i] != ' ') {
        word[i] += key;
        word[i] %= 26;
      }
    }
  }
}

