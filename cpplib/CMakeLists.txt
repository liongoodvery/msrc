cmake_minimum_required(VERSION 3.7)
project(cpplib)

set(CMAKE_CXX_STANDARD 11)
SET (CMAKE_C_COMPILER             "/usr/bin/clang")
SET (CMAKE_C_FLAGS                "-Wall -std=c99")
SET (CMAKE_C_FLAGS_DEBUG          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
SET (CMAKE_CXX_FLAGS                "-Wall -Werror")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_AR      "/usr/bin/llvm-ar")
SET (CMAKE_LINKER  "/usr/bin/llvm-ld")
SET (CMAKE_NM      "/usr/bin/llvm-nm")
SET (CMAKE_OBJDUMP "/usr/bin/llvm-objdump")
SET (CMAKE_RANLIB  "/usr/bin/llvm-ranlib")

add_executable(2 2.cpp)
add_executable(algo1 algo1.cpp)
add_executable(algo2 algo2.cpp)
add_executable(array array.cpp)
add_executable(deque deque.cpp)
add_executable(fileio fileio.cpp)
add_executable(forloop forloop.cpp)
add_executable(initializer initializer.cpp)
add_executable(iterator iterator.cpp)
add_executable(iterator2 iterator2.cpp)
add_executable(lambda lambda.cpp)
add_executable(list list.cpp)
add_executable(map map.cpp)
add_executable(pair pair.cpp)
add_executable(rawstring rawstring.cpp)
add_executable(Sample Sample.cpp)
add_executable(set set.cpp)
add_executable(sharedptr sharedptr.cpp)
add_executable(tuple tuple.cpp)
add_executable(vector vector.cpp)
add_executable(citerator citerator.cpp)
