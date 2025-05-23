cmake_minimum_required(VERSION 2.8)
project(pose_graph)

# set debug
set(CMAKE_BUILD_TYPE Debug)
# set debug flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# Eigen
include_directories("/usr/include/eigen3")

# sophus 
#find_package(Sophus REQUIRED)
#include_directories(${Sophus_INCLUDE_DIRS})

# g2o 
find_package(g2o REQUIRED)
include_directories(${G2O_INCLUDE_DIRS})

add_executable(pose_graph_g2o_SE3 src/pose_graph_g2o_SE3.cpp)
target_link_libraries(pose_graph_g2o_SE3
        g2o_core g2o_stuff g2o_types_slam3d ${CHOLMOD_LIBRARIES}
        )

add_executable(pose_graph_g2o_lie src/pose_graph_g2o_lie_algebra.cpp)
target_link_libraries(pose_graph_g2o_lie
        g2o_core g2o_stuff
        ${CHOLMOD_LIBRARIES}
        ${Sophus_LIBRARIES}
        )

