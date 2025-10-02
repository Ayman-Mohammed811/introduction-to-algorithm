cmake_minimum_required(VERSION 4.0)
project(introduction_to_algorithm)

set(CMAKE_CXX_STANDARD 23)

add_executable(introduction_to_algorithm
        src/main.cpp
        include/datastructure/nodes.h
        include/datastructure/queue.h
        include/datastructure/stack.h
        include/sort/insertion_sort.h)
