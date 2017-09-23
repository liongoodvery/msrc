cmake_minimum_required(VERSION 3.7)
project(procpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(procpp ${SOURCE_FILES})

add_executable(stringTest stringTest.cpp)
add_executable(quick_sort quick_sort.cpp)
add_executable(l6.6.c l6.6.c)