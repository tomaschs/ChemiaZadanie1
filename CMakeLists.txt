cmake_minimum_required(VERSION 3.27)
project(Zadanie1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Zadanie1 main.cpp
        suffix_node.cpp
        suffix_node.h
        suffix_tree.cpp
        suffix_tree.h)
