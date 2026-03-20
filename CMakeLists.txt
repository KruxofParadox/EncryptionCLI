cmake_minimum_required(VERSION 4.2)
project(ecrypt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
add_executable(${PROJECT_NAME} src/main.cpp)
add_library(utils src/utils.cpp)

target_link_libraries(${PROJECT_NAME} utils)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests include/utils.h src/utils.cpp tests/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(tests)