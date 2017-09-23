#!/bin/bash
filename=$1
if [ -z "$filename" ] ; then
	echo "filename:"
	read filename
fi


cp Sample.cpp "$filename.cpp"

if [ -f "CMakeLists.txt" ] ; then
    echo "add_executable(${filename} ${filename}.cpp)" >> CMakeLists.txt;
fi