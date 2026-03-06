#pragma once
#include <string>
#include <vector>

void printUsage();
void getUserFunction(int numArguments, char* arguments[], std::vector<std::string>* filecontents);
bool checkValidFile(std::string filename);
std::vector<std::string> readFromFile(std::string filename);