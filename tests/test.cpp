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

