

project(examples)
# set debug mode
set(CMAKE_BUILD_TYPE Debug)
# set flag debug
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_STANDARD 11)

include_directories("/usr/include/eigen3")
add_executable(coordinateTransform coordinateTransform.cpp)

find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
add_executable(plotTrajectory plotTrajectory.cpp)
target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES})
