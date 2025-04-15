cmake_minimum_required(VERSION 2.8)

project(bundle_adjustment)

# set debug
set(CMAKE_BUILD_TYPE Debug)
# set debug flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


set(Eigen3_DIR "/usr/share/eigen3/cmake")

# Find packages
find_package(Eigen3 REQUIRED)
find_package(Ceres REQUIRED)
find_package(g2o REQUIRED)


# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${EIGEN3_INCLUDE_DIR}
    ${CERES_INCLUDE_DIRS}
    /usr/include/suitesparse # <-- utile pour CSparse
)

# G2O libraries
set(G2O_LIBS
    g2o_csparse_extension
    g2o_core
    g2o_stuff
    g2o_solver_csparse
    cxsparse
)


# Targets
add_library(bal_common src/common.cpp)

add_executable(bundle_adjustment_g2o src/bundle_adjustment_g2o.cpp)
target_link_libraries(bundle_adjustment_g2o ${G2O_LIBS} bal_common)

add_executable(bundle_adjustment_ceres src/bundle_adjustment_ceres.cpp)
target_link_libraries(bundle_adjustment_ceres ${CERES_LIBRARIES} bal_common)
