cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2 -std=c++11")

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

project(list)

add_executable(list_ex1 list_ex1.cpp)
target_link_libraries(list_ex1 m)

add_executable(list_ex2 list_ex2.cpp)
target_link_libraries(list_ex2 m)

