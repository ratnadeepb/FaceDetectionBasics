# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

# Minimum CMake version
cmake_minimum_required(VERSION 2.8)

# Set project name
set(PROJECT_NAME "threeVision")
project("$PROJECT_NAME")

# OpenCV requirement
find_package( OpenCV REQUIRED )

INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )
SET(OpenCV_LIBRARIES ${OpenCV_LIBS})

# this is a C++11 project
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Add the subdirectories
add_subdirectory(ImgOps)
add_subdirectory(pixelManipulation)
add_subdirectory(colorManipulation)
