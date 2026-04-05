#pragma once
#include <string>
#include <vector>

void printUsage();
void printHelp();
void printError(std::string argument);
int determineOptionOrCommand(std::string argument);
bool checkFileExtension(std::string filename);
void getFunction(int numArguments, char* arguments[], std::vector<std::string>* filecontents);
void getFunctionInfo(char* arguments[]);
void useFunction(char* arguments[], std::vector<std::string>* filecontents);
void writeToFile(std::vector<std::string>* filecontents, std::string filename);
bool checkValidFile(std::string filename);
std::vector<std::string> readFromFile(std::string filename);
void encryptFile(std::vector<std::string>* filecontents);
int parseUserCipher(std::string userCipher);
std::vector<std::string> splitString(std::string toSplit, char delimiter);
void runCaesarCipher(std::vector<std::string>* filecontents, int key);