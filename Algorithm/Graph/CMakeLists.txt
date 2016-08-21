cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2 -std=c++11")

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -std=c++11")

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

# for Boost::graph
#find_package( Boost 1.54 COMPONENTS graph REQUIRED )
set(Boost_INCLUDE_DIR /usr/include)
set(Boost_LIBRARIES boost_graph)
#link_directories(/usr/lib/x86_64-linux-gnu)
include_directories( ${Boost_INCLUDE_DIR} )

project(Graph)

add_executable(dfs dfs.cpp)
target_link_libraries(dfs ${Boost_LIBRARIES} m)

add_executable(dijkstra dijkstra.cpp)
target_link_libraries(dijkstra ${Boost_LIBRARIES} m)

add_executable(bellman-ford bellman-ford.cpp)
target_link_libraries(bellman-ford ${Boost_LIBRARIES} m)
