cmake_minimum_required(VERSION 3.7)
project(opencv)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        e0201.cpp)

SET(OPENCV_LIB opencv_highgui opencv_core opencv_imgcodecs opencv_imgproc opencv_videoio opencv_video opencv_videostab)
add_executable(e0201 e0201.cpp)
target_link_libraries(e0201 ${OPENCV_LIB})

add_executable(e0203 e0203.cpp)
target_link_libraries(e0203 ${OPENCV_LIB})


add_executable(e0205 e0205.cpp)
target_link_libraries(e0205 ${OPENCV_LIB})


add_executable(e0207 e0207.cpp)
target_link_libraries(e0207 ${OPENCV_LIB})


add_executable(test1 test1.cpp)
target_link_libraries(test1 ${OPENCV_LIB})
