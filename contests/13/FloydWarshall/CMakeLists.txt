cmake_minimum_required(VERSION 3.0)
project(floyd_warshall)

set(CMAKE_CXX_STANDARD 11)

add_executable(floyd_warshall main.cpp Edge.h ReadWriter.h)
