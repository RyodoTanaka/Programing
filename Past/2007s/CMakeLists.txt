cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2 -std=c++11")

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -std=c++11")

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

project(2007s)

add_executable(q1 q1.cpp)
target_link_libraries(q1 m)

add_executable(q1-ex q1-ex.cpp)
target_link_libraries(q1-ex m)

add_executable(q21 q21.cpp)
target_link_libraries(q21 m)

add_executable(q31 q31.cpp)
target_link_libraries(q31 m)
