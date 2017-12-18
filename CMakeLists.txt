
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project( midpoint )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

find_library(COCOA Cocoa)

include_directories(
    include
    ${OPENGL_INCLUDE_DIR}
    ${GLUT_INCLUDE_DIR}
)

add_executable(
    midpoint
    src/main.cpp
    src/Display.cpp
    src/Circle.cpp
)

target_link_libraries(
    midpoint
    ${OPENGL_LIBRARIES}
    ${COCOA_LIBRARIES}
    ${GLUT_LIBRARIES}
)