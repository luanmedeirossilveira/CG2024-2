cmake_minimum_required(VERSION 3.16)
project(OpenGLExample)

set(CMAKE_CXX_STANDARD 17)

# Diretórios das bibliotecas dentro da pasta dependencies
set(GLFW_DIR "${CMAKE_SOURCE_DIR}/Dependencies/glfw-3.4.bin.WIN64")
set(GLAD_DIR "${CMAKE_SOURCE_DIR}/Dependencies/GLAD")
set(GLM_DIR "${CMAKE_SOURCE_DIR}/Dependencies/glm")

# Adiciona os diretórios de include e de bibliotecas
include_directories("${GLFW_DIR}/include" "${GLAD_DIR}/include" "${GLM_DIR}")
link_directories("${GLFW_DIR}/lib-static-ucrt")

# 0-Hello3D
#[[add_library(glad "${GLAD_DIR}/src/glad.c")
add_executable(OpenGLExample 0-Hello3D/Source.cpp)]]

# 1-Environment3DScenes
#[[add_library(glad "${GLAD_DIR}/src/glad.c"
		1-Environment3DScenes/Shader/Shader.h
		1-Environment3DScenes/Shader/Shader.cpp
		1-Environment3DScenes/Geometry/Geometry.h
		1-Environment3DScenes/Geometry/Geometry.cpp
		1-Environment3DScenes/Callbacks/Callbacks.h
		1-Environment3DScenes/Callbacks/Callbacks.cpp
		1-Environment3DScenes/Source.cpp)
add_executable(OpenGLExample 1-Environment3DScenes/Source.cpp)]]

# 2-Textures
add_library(glad "${GLAD_DIR}/src/glad.c")
add_executable(OpenGLExample 2-Hello3D-Camera/Source.cpp)


# Linka as bibliotecas (Ajuste os nomes conforme o seu sistema)
if (WIN32)
	target_link_libraries(OpenGLExample OpenGL32 glfw3.lib glad)
else()
	target_link_libraries(OpenGLExample ${OPENGL_LIBRARIES} glfw glad)
endif()
