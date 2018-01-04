# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

# Minimum CMake version
cmake_minimum_required(VERSION 2.8)

# OpenCV requirement
find_package( OpenCV REQUIRED )

# Add the subdirectories
add_subdirectory(ImgOps)
add_subdirectory(pixelManipulation)
add_subdirectory(colorManipulation)
