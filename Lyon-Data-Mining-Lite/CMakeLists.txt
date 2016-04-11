cmake_minimum_required(VERSION 3.1)
project(tp2-g)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES EventArchivePerDay.cpp EventArchivePerHour.cpp EventArchivePerMinute.cpp Sensor.h SensorTree.h EventArchivePerDay.h EventArchivePerHour.h EventArchivePerMinute.h Sensor.cpp SensorTree.cpp ./BinaryTreeG/BinaryTreeG.hpp ./BinaryTreeG/BinaryTreeGNodes.h ./BinaryTreeG/BinaryTreeGNodes.cpp ./BinaryTreeG/BinaryTreeG.tcc)

add_executable(main ${SOURCE_FILES} main.cpp)
