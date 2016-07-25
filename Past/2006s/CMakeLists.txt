cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2 -std=c++11")

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

project(2006s)

add_executable(3a 3a.cpp)
target_link_libraries(3a m)
