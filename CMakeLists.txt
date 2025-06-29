cmake_minimum_required(VERSION 3.31)
project(zip_forge)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(zip_forge src/main.cpp
        include/huffman.h
        src/huffman.cpp)
