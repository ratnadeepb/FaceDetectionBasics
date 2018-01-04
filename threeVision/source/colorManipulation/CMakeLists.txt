# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

# Minimum cmake version
cmake_minimum_required(VERSION 2.8)

# Executables
add_executable(detectColor detectColor.cpp)

# Linker
target_link_libraries(detectColor "${OpenCV_LIBS}")
