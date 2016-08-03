cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2 -std=c++11")

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

project(map)

add_executable(ex1 ex1.cpp)
target_link_libraries(ex1 m)

add_executable(go_around1 go_around1.cpp)
target_link_libraries(go_around1 m)

add_executable(go_around2 go_around2.cpp)
target_link_libraries(go_around2 m)
