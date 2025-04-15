cmake_minimum_required(VERSION 2.8)
project(vo1)


# set debug
set(CMAKE_BUILD_TYPE Debug)
# set debug flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(Eigen3_DIR "/usr/share/eigen3/cmake")

find_package(OpenCV REQUIRED)
find_package(g2o REQUIRED)
#find_package(Sophus REQUIRED)

include_directories(
        ${OpenCV_INCLUDE_DIRS}
        ${G2O_INCLUDE_DIRS}
        ${Sophus_INCLUDE_DIRS}
        "/usr/include/eigen3/"
)

#add_executable(orb_cv src/orb_cv.cpp)
#target_link_libraries(orb_cv ${OpenCV_LIBS})

#add_executable(orb_self src/orb_self.cpp)
#target_link_libraries(orb_self ${OpenCV_LIBS})

#add_executable( pose_estimation_2d2d pose_estimation_2d2d.cpp extra.cpp ) # use this if in OpenCV2 
#add_executable(pose_estimation_2d2d src/pose_estimation_2d2d.cpp)
#target_link_libraries(pose_estimation_2d2d ${OpenCV_LIBS})

# # # add_executable( triangulation triangulation.cpp extra.cpp) # use this if in opencv2
# add_executable(triangulation src/triangulation.cpp)
# target_link_libraries(triangulation ${OpenCV_LIBS})

add_executable(pose_estimation_3d2d src/pose_estimation_3d2d.cpp)
target_link_libraries(pose_estimation_3d2d
        g2o_core g2o_stuff
        ${OpenCV_LIBS})

# add_executable(pose_estimation_3d3d src/pose_estimation_3d3d.cpp)
# target_link_libraries(pose_estimation_3d3d
#         g2o_core g2o_stuff
#         ${OpenCV_LIBS})
