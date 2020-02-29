cmake_minimum_required(VERSION 3.0)
project(merge_sort)

set(CMAKE_CXX_STANDARD 11)

add_executable(merge_sort main.cpp MergeSort.h ReadWriter.h)