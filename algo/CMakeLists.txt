cmake_minimum_required(VERSION 3.7)
project(algo)

set(CMAKE_CXX_STANDARD 11)
include_directories("./include")

set(LIST_SRC
        test/listTest.c)
set (LIB_SRC
        list.c
        dlist.c
        stack.c
        queue.c
        set.c
        chtbl.c
        hashpjw.c
        bitree.c
        )

add_library(algo STATIC ${LIB_SRC})

add_subdirectory("test")

