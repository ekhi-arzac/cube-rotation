cmake_minimum_required(VERSION 3.24)
project(cube_rotation)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR C:/libs/SDL/include)
set(SDL2_LIB_DIR C:/libs/SDL/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(cube_rotation src/main.cpp src/Window.cpp src/Point.cpp src/Polyhedron.cpp)

target_link_libraries(cube_rotation SDL2main SDL2)