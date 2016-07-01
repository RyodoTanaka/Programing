cmake_minimum_required(VERSION 2.6)

set(CMAKE_CPP_FLAGS_RELEASE "-Wall -O2 -std=c++11")

set(CMAKE_CPP_FLAGS_DEBUG "-g -O0")

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

project(2006w)

add_executable(33 33.cpp)

target_link_libraries(33 m)
