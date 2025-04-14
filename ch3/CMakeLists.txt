cmake_minimum_required(VERSION 2.8)
project(chapter3)

# pour debug
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Définir le standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_subdirectory(src/useEigen)
add_subdirectory(src/useGeometry)
add_subdirectory(src/visualizeGeometry)
add_subdirectory(src/examples)
