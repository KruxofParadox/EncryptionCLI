#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <string>
#include "../include/utils.h"

TEST_CASE("SplitString with space delimiter", "[splitString]") {  
  REQUIRE(splitString("this is a test", ' ') == std::vector<std::string>{"this", "is", "a", "test"});
  REQUIRE(splitString(" another test", ' ') == std::vector<std::string>{"another", "test"});
}

TEST_CASE("SplitString with comma delimiter", "[splitString]") {
  REQUIRE(splitString("comma,separated,values", ',') == std::vector<std::string>{"comma", "separated", "values"});
}

TEST_CASE("Caesar Cipher") {
  std::vector<std::string> test1 = {"aaaa"};
  std::vector<std::string> test2 = {"test test test"};
  runCaesarCipher(&test1, 1);
  runCaesarCipher(&test2, 2);

  REQUIRE(test1 == std::vector<std::string>{"bbbb"});
  REQUIRE(test2 == std::vector<std::string>{"vguv vguv vguv"});
}

