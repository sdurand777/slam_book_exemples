cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(Chapitre2)


# pour debug
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Définir le standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter l'exécutable
add_executable(main src/helloSLAM2.cpp)

add_library(hello_shared SHARED src/libHelloSLAM.cpp)
add_executable(useHello src/useHello.cpp)
target_link_libraries(useHello hello_shared)
