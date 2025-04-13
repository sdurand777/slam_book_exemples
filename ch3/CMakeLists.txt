cmake_minimum_required(VERSION 2.8)
project(chapter3)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_subdirectory(src/useEigen)
add_subdirectory(src/useGeometry)
add_subdirectory(src/visualizeGeometry)
add_subdirectory(src/examples)
