cmake_minimum_required(VERSION 2.8)
project(ch6)

# set cmake debug
set(CMAKE_BUILD_TYPE Debug)
# set flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Eigen
include_directories("/usr/include/eigen3")
# set Eigen3_DIR "/usr/include/eigen3") 
set(Eigen3_DIR "/usr/share/eigen3/cmake")

# Ceres
find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

# g2o
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/cmake/g2o")
find_package(g2o REQUIRED)
include_directories(${G2O_INCLUDE_DIRS})

add_executable(gaussNewton src/gaussNewton.cpp)
target_link_libraries(gaussNewton ${OpenCV_LIBS})

add_executable(ceresCurveFitting src/ceresCurveFitting.cpp)
target_link_libraries(ceresCurveFitting ${OpenCV_LIBS} ${CERES_LIBRARIES})

add_executable(g2oCurveFitting src/g2oCurveFitting.cpp)
#target_link_libraries(g2oCurveFitting ${OpenCV_LIBS} ${G2O_CORE_LIBRARY} ${G2O_STUFF_LIBRARY})
target_link_libraries(g2oCurveFitting ${OpenCV_LIBS} g2o_core g2o_stuff)