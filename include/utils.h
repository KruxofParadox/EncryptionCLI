#pragma once
#include <string>
#include <vector>

std::string cipherList[] = {
  "caesar"
};

void printUsage();
void printHelp();
int determineOptionOrCommand(std::string argument);
bool checkFileExtension(std::string filename);
void getUserFunction(int numArguments, char* arguments[], std::vector<std::string>* filecontents);
bool checkValidFile(std::string filename);
std::vector<std::string> readFromFile(std::string filename);
void encryptFile(std::vector<std::string>* filecontents);
int parseUserCipher(std::string userCipher);
