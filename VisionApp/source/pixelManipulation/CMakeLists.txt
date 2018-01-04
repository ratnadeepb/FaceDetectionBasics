# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

# Minimum cmake version
cmake_minimum_required(VERSION 2.8)

# Sub source
set(sub_source_dir "pixelManipulation")

# Executables
add_executable(saltPepper saltPepper.cpp saltPepper.hpp)
add_executable(reduceColor reduceColor.hpp reduceColor.cpp)
add_executable(reduceColorEfficient reduceColorEfficient.hpp reduceColorEfficient.cpp)
add_executable(reduceColorMatrix reduceColorMatrix.hpp reduceColorMatrix.cpp)
add_executable(reduceColorIterator reduceColorIterator.hpp reduceColorIterator.cpp)
add_executable(sharpenEdges sharpenEdges.hpp sharpenEdges.cpp)
add_executable(addImgs addImgs.hpp addImgs.cpp)
add_executable(splitProcess splitProcess.hpp splitProcess.cpp)

# Linker
target_link_libraries(saltPepper "${OpenCV_LIBS}")
target_link_libraries(reduceColor "${OpenCV_LIBS}")
target_link_libraries(reduceColorEfficient "${OpenCV_LIBS}")
target_link_libraries(reduceColorMatrix "${OpenCV_LIBS}")
target_link_libraries(reduceColorIterator "${OpenCV_LIBS}")
target_link_libraries(sharpenEdges "${OpenCV_LIBS}")
target_link_libraries(addImgs "${OpenCV_LIBS}")
target_link_libraries(splitProcess "${OpenCV_LIBS}")

# Set the output folder where your program will be created
#if(CMAKE_BUILD_TYPE Matches Debug)
if(CMAKE_BUILD_TYPE MATCHES Release)
   set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build/Release/pixelManipulation/)
else(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build/Debug/pixelManipulation/)
endif(CMAKE_BUILD_TYPE MATCHES Release)
message(STATUS "        ${sub_source_dir} - Build Path: ${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
