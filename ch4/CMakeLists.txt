cmake_minimum_required(VERSION 3.0)
project(useSophus)

# set debug mode
set(CMAKE_BUILD_TYPE Debug)
# set debug flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
# set C++ standard
set(CMAKE_CXX_STANDARD 17)

#find_package(Sophus REQUIRED)

# Eigen
include_directories("/usr/include/eigen3")
add_executable(useSophus src/useSophus.cpp)
#target_link_libraries(useSophus Sophus::Sophus)

add_subdirectory(src/example)
