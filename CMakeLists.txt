cmake_minimum_required(VERSION 3.31)
project(zip_forge)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(zip_forge src/main.cpp
        include/huffman.h
        include/lz77.h
        src/huffman.cpp
        src/lz77.cpp)
