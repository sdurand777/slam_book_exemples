cmake_minimum_required( VERSION 2.8 )
project( geometry )

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

include_directories( "/usr/include/eigen3" )

add_executable(eigenGeometry useGeometry.cpp)
