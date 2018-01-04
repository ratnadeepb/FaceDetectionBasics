# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

# Minimum cmake version
cmake_minimum_required(VERSION 2.8)

# Executables
add_executable(basicOps basicOps.cpp runImgs.cpp basicOps.hpp)
add_executable(flipImg flipImg.cpp flipImg.hpp basicOps.cpp basicOps.hpp)
add_executable(findImgChannels findImgChannels.cpp)
add_executable(convertToGray convertToGray.cpp)

# Link directives
target_link_libraries(basicOps ${OpenCV_LIBS})
target_link_libraries(flipImg ${OpenCV_LIBS})
target_link_libraries(findImgChannels "${OpenCV_LIBS}")
target_link_libraries(convertToGray "${OpenCV_LIBS}")
