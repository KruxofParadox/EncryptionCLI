#pragma once
#include <string>
#include <vector>

void printUsage();
void printHelp();
int determineOptionOrCommand(std::string argument);
bool checkForTextFile(std::string filename);
void getUserFunction(int numArguments, char* arguments[], std::vector<std::string>* filecontents);
bool checkValidFile(std::string filename);
std::vector<std::string> readFromFile(std::string filename);