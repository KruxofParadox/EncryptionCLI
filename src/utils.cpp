#include "../include/utils.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

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

void printError(std::string argument) {
      if (determineOptionOrCommand(argument)) {
      std::cerr << "unknown option: " << argument << std::endl;
      printUsage();         
    }
    else
      std::cerr << "ecrypt: \'" << argument << "\' is not an ecrypt command. See \'ecrypt --help\'" << std::endl; 
}

void getUserFunction(int numArguments, char* arguments[], std::vector<std::string>* filecontents) {
  if (std::strcmp(arguments[1], "-e") || std::strcmp(arguments[1], "encrypt")) {
    if (checkValidFile(arguments[2])) {          
      *filecontents = readFromFile(arguments[2]);
      encryptFile(filecontents);
      writeToFile(filecontents, arguments[2]);
    }
  }
  else
    printError(arguments[1]); 
}

void getHelpFunction(char* arguments[]) {
  if (std::strcmp(arguments[1], "-c") || std::strcmp(arguments[1], "cipher")) {
    if (checkValidFile(arguments[2])) {          
      
    }}
}

void writeToFile(std::vector<std::string>* filecontents, std::string filename) {
  auto splitFilename = splitString(filename, '/');
  auto updatedFilename = splitFilename[0] + "/encrypted_" + splitFilename[1];

  std::ofstream encryptedFile(updatedFilename);

  for (auto word: *filecontents)
    encryptedFile << word;

  encryptedFile.close();
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
  auto userInputs = splitString(userCipher, ' ');

  if (userInputs[0] == "caesar")
    runCaesarCipher(filecontents, std::stoi(userInputs[1]));
  else 
    std::cerr << "Error: \'" << userCipher << "\' is not a valid cipher" << std::endl;
}

std::vector<std::string> splitString(std::string toSplit, char delimiter) {
  std::vector<std::string> split;
  std::string userArgument;
  for (auto letter: toSplit) {
    if (letter == delimiter) {
      split.push_back(userArgument);
      userArgument = "";
    }
    else 
      userArgument += letter;
  }

  split.push_back(userArgument);
  std::erase(split, "");

  return split;
}

void runCaesarCipher(std::vector<std::string>* filecontents, int key) {
  for (auto i = 0; i < filecontents->size(); i++) {
    for (auto j = 0; j < filecontents->at(i).size(); j++) {
      if ((*filecontents)[i][j] != ' ') {
        (*filecontents)[i][j] -= 'a';
        (*filecontents)[i][j] += key;
        (*filecontents)[i][j] %= 26;
        (*filecontents)[i][j] += 'a';
      }
    }
  }
}
