cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2 -std=c++11")

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

project(2007s)

add_executable(1 1.cpp)
target_link_libraries(1 m)

add_executable(1_ex 1_ex.cpp)
target_link_libraries(1_ex m)

