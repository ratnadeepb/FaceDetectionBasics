# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

# Minimum cmake version
cmake_minimum_required(VERSION 2.8)

# Sub source
set(sub_source_dir "colorManipulation")

# Executables
add_executable(detectColor ColorDetector.hpp ColorDetector.cpp detectColor.cpp)

# Linker
target_link_libraries(detectColor "${OpenCV_LIBS}")

# Set the output folder where your program will be created
if(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build/Release/colorManipulation/)
else(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build/Debug/colorManipulation/)
endif(CMAKE_BUILD_TYPE MATCHES Release)
message(STATUS "        ${sub_source_dir} - Build Path: ${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
