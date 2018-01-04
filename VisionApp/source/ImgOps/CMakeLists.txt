# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

# Minimum cmake version
cmake_minimum_required(VERSION 2.8)

# Sub source
set(sub_source_dir "ImgOps")

# Executables
add_executable(basicOps basicOps.cpp runImgs.cpp)
add_executable(flipImg flipImg.cpp basicOps.cpp)
add_executable(findImgChannels findImgChannels.cpp)
add_executable(convertToGray convertToGray.cpp)

# Link directives
target_link_libraries(basicOps ${OpenCV_LIBS})
target_link_libraries(flipImg ${OpenCV_LIBS})
target_link_libraries(findImgChannels "${OpenCV_LIBS}")
target_link_libraries(convertToGray "${OpenCV_LIBS}")

# Set the output folder where your program will be created
if(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build/Release/ImgOps/)
else(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build/Debug/ImgOps/)
endif(CMAKE_BUILD_TYPE MATCHES Release)
message(STATUS "        ${sub_source_dir} - Build Path: ${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
