cmake_minimum_required(VERSION 4.2)
project(ecrypt)
add_executable(${PROJECT_NAME} src/main.cpp)
add_library(utils src/utils.cpp)

target_link_libraries(${PROJECT_NAME} utils)
