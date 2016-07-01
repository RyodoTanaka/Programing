cmake_minimum_required(VERSION 2.6)

set(CMAKE_CPP_FLAGS_RELEASE "-Wall -O2 -std=c++11")

set(CMAKE_CPP_FLAGS_DEBUG "-g -O0")

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

project(algorithm)

add_executable(count_ex1 count_ex1.cpp)
target_link_libraries(count_ex1 m)

add_executable(count_ex2 count_ex2.cpp)
target_link_libraries(count_ex2 m)

add_executable(rm_rp_ex1 rm_rp_ex1.cpp)
target_link_libraries(rm_rp_ex1 m)

add_executable(rev_ex1 rev_ex1.cpp)
target_link_libraries(rev_ex1 m)

add_executable(trans_ex1 trans_ex1.cpp)
target_link_libraries(trans_ex1 m)



