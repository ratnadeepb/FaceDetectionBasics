# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

# Minimum cmake version
cmake_minimum_required(VERSION 2.8)

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
