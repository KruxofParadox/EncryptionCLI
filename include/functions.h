#pragma once
#include <string>
#include <vector>

enum class ENCRYPTIONTYPE: int {
  caesarCipher
};

void printUsage();
void printHelp();
int determineOptionOrCommand(std::string argument);
bool checkForTextFile(std::string filename);
void getUserFunction(int numArguments, char* arguments[], std::vector<std::string>* filecontents);
bool checkValidFile(std::string filename);
std::vector<std::string> readFromFile(std::string filename);
void encryptFile(std::vector<std::string>* filecontents, ENCRYPTIONTYPE encryptionType = ENCRYPTIONTYPE::caesarCipher);