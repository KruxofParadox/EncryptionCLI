#pragma once
#include <string>
#include <vector>

void getUserFunction(int numArguments, char* arguments[], std::vector<std::string>* filecontents);
bool checkFileValid(std::string filename);
std::vector<std::string> readFromFile(std::string filename);