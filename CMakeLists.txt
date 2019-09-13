cmake_minimum_required(VERSION 3.13)
project(opengl_learning)

set(CMAKE_CXX_STANDARD 14)

### configure version info ###
set(opengl_learning_VERSION_MAJOR 1)
set(opengl_learning_VERSION_MINOR 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/Version.h.in"
        "${PROJECT_BINARY_DIR}/Version.h"
)
include_directories("${PROJECT_BINARY_DIR}")

### common libs ###
include_directories("${PROJECT_SOURCE_DIR}/common")
add_subdirectory(${PROJECT_SOURCE_DIR}/common)

### OPENGL ###
find_package(OpenGL REQUIRED)
link_directories(${OpenGL_LIBRARY_DIRS})
include_directories(${OpenGL_INCLUDE_DIR})

### GLFW ###
add_subdirectory("${PROJECT_SOURCE_DIR}/external/glfw-3.3")
include_directories("${PROJECT_SOURCE_DIR}/external/glfw-3.3/include")

### GLM ###
include_directories("${PROJECT_SOURCE_DIR}/external/glm-0.9.9.6")

### GLEW ###
add_subdirectory("${PROJECT_SOURCE_DIR}/external/glew-2.1.0/build/cmake")
include_directories("${PROJECT_SOURCE_DIR}/external/glew-2.1.0/include")

### set extra libraries ###
set(EXTRA_LIBS ${EXTRA_LIBS} common ${OPENGL_LIBRARIES} glew glfw)

### build and link ###
add_executable(${PROJECT_NAME} main.cpp Version.h.in)
target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})