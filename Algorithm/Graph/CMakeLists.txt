cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2 -std=c++11")

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -std=c++11")

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

project(Graph)

add_executable(dfs dfs.cpp)
target_link_libraries(dfs m)
