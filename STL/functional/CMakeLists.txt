cmake_minimum_required(VERSION 2.6)

set(CMAKE_CPP_FLAGS_RELEASE "-Wall -O2 -std=c++11")

set(CMAKE_CPP_FLAGS_DEBUG "-g -O0")

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

project(algorithm)

add_executable(func_ex1 func_ex1.cpp)
target_link_libraries(func_ex1 m)

add_executable(func_ex2 func_ex2.cpp)
target_link_libraries(func_ex2 m)


