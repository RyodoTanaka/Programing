cmake_minimum_required(VERSION 2.6)

set(CMAKE_CPP_FLAGS_RELEASE "-Wall -O2 -std=c++11")

set(CMAKE_CPP_FLAGS_DEBUG "-g -O0")

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

project(vector)

add_executable(ex1 ex1.cpp)
target_link_libraries(ex1 m)

add_executable(iterator_ex1 iterator_ex1.cpp)
target_link_libraries(iterator_ex1 m)

add_executable(iterator_ex2 iterator_ex2.cpp)
target_link_libraries(iterator_ex2 m)


