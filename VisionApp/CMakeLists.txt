# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

# Minimum CMake version
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Project Name
set(project_name "VisionApp")
project("${project_name}")

# C++11 support
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -Wextra -std=c++11")
# cmake /home/ratnadeepb/app/MyPrograms/cv/cpp/VisionApp -DCMAKE_BUILD_TYPE=Debug
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11")
# cmake /home/ratnadeepb/app/MyPrograms/cv/cpp/VisionApp -DCMAKE_BUILD_TYPE=Release

# add opencv package to the project
find_package( OpenCV REQUIRED )
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} ) 
SET(OpenCV_LIBRARIES ${OpenCV_LIBS})

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# OpenCV requirement
find_package( OpenCV REQUIRED )

# Add the subdirectories
add_subdirectory(source)
