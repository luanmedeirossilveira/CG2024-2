cmake_minimum_required(VERSION 3.16)
project(OpenGLTBGA)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_DIR "${CMAKE_SOURCE_DIR}/Dependencies/glfw-3.4.bin.WIN64")
set(GLAD_DIR "${CMAKE_SOURCE_DIR}/Dependencies/GLAD")
set(GLM_DIR "${CMAKE_SOURCE_DIR}/Dependencies/glm")

include_directories("${GLFW_DIR}/include" "${GLAD_DIR}/include" "${GLM_DIR}")
link_directories("${GLFW_DIR}/lib-static-ucrt")

add_library(glad "${GLAD_DIR}/src/glad.c")
add_executable(OpenGLTBGA Iluminacao/Source.cpp)

if (WIN32)
	target_link_libraries(OpenGLTBGA OpenGL32 glfw3.lib glad)
else()
	target_link_libraries(OpenGLTBGA ${OPENGL_LIBRARIES} glfw glad)
endif()
