cmake_minimum_required(VERSION 3.7)
project(algo)

set(CMAKE_CXX_STANDARD 11)
include_directories("../include")

add_library(mytest mytest.c)
add_executable(Test Test.c)
add_executable(listTest listTest.c)
target_link_libraries(listTest algo mytest)


add_executable(dlistTest dlistTest.c)
target_link_libraries(dlistTest algo mytest)

add_executable(stackTest stackTest.c)
target_link_libraries(stackTest algo mytest)

add_executable(queueTest queueTest.c)
target_link_libraries(queueTest algo mytest)

add_executable(setTest setTest.c)
target_link_libraries(setTest algo mytest)


add_executable(chtblTest chtblTest.c)
target_link_libraries(chtblTest algo mytest)

add_executable(bitreeTest bitreeTest.c)
target_link_libraries(bitreeTest algo mytest)


add_executable(insert_sort insert_sort.c)
add_executable(max_sub_array max_sub_array.c)
target_link_libraries(max_sub_array m)