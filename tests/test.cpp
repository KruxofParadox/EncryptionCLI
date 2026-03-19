#include <catch2/catch_test_macros.hpp>
#include <vector>
#include "../include/utils.h"

TEST_CASE("Addition", "[add]") {
  REQUIRE(add(1, 2) == 3);
}