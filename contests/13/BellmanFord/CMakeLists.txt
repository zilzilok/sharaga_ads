cmake_minimum_required(VERSION 3.0)
project(bellman_ford)

set(CMAKE_CXX_STANDARD 11)

add_executable(bellman_ford main.cpp Edge.h ReadWriter.h)
