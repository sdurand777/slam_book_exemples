cmake_minimum_required(VERSION 2.8)

# set debug mode
set(CMAKE_BUILD_TYPE Debug)
# set debug flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# Eigen
include_directories("/usr/include/eigen3")

# 寻找OpenCV库
find_package(OpenCV REQUIRED)
# 添加头文件
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(src/imageBasics)
add_subdirectory(src/stereo)
add_subdirectory(src/rgbd)
