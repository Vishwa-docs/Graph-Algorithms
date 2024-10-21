cmake_minimum_required(VERSION 3.27)
project(Graphs_BFS_Algorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(Graphs_BFS_Algorithm main.cpp
        Graph.h
        Graph.cpp
        Search.h
        Search.cpp)