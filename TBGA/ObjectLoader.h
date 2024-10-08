#ifndef OBJECT_LOADER_H
#define OBJECT_LOADER_H

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

struct Object
{
    GLuint VAO;
    GLuint VBO;
    int nVertices;
    glm::mat4 model;
};

int loadModel(const std::string &filePath, Object &obj);

#endif
