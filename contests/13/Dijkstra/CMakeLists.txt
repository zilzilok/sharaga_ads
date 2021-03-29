cmake_minimum_required(VERSION 3.0)
project(dijkstra)

set(CMAKE_CXX_STANDARD 11)

add_executable(dijkstra main.cpp Edge.h ReadWriter.h)
