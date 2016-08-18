cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2 -std=c++11")

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -std=c++11")

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

project(2008s)

add_executable(q21 q21.cpp)
target_link_libraries(q21 m)

add_executable(q22 q22.cpp)
target_link_libraries(q22 m)

add_executable(q23 q23.cpp)
target_link_libraries(q23 m)

add_executable(q24-ex q24-ex.cpp)
target_link_libraries(q24-ex m)

add_executable(q24 q24.cpp)
target_link_libraries(q24 m)
