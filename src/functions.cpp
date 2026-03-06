#include "../include/functions.h"
#include <fstream>

std::vector<std::string> readFromFile(std::string filename) {
  std::vector<std::string> filedata;
  std::string line;
  std::ifstream file(filename);

  while (std::getline(file, line)) {
    filedata.push_back(line);
  }

  return filedata;
}