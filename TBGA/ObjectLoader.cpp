#include "ObjectLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

int loadModel(const std::string &filePath, Object &obj)
{
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<GLuint> indices;
    std::vector<GLfloat> vboData;  // Intercalar vértices e normais

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo: " << filePath << std::endl;
        return -1;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string prefix;
        ss >> prefix;

        if (prefix == "v")
        {
            // Lê as coordenadas do vértice
            glm::vec3 vertex;
            ss >> vertex.x >> vertex.y >> vertex.z;
            vertices.push_back(vertex);
        }
        else if (prefix == "vn")
        {
            // Lê as normais
            glm::vec3 normal;
            ss >> normal.x >> normal.y >> normal.z;
            normals.push_back(normal);
        }
        else if (prefix == "f")
        {
            // Lê as faces (vértice/normal)
            GLuint vertexIndex[3], normalIndex[3];
            char slash;
            for (int i = 0; i < 3; ++i)
            {
                ss >> vertexIndex[i] >> slash >> slash >> normalIndex[i];

                // OBJ usa índice 1, então subtraímos 1 para adaptar a arrays de C++ (índice 0)
                glm::vec3 vertex = vertices[vertexIndex[i] - 1];
                glm::vec3 normal = normals[normalIndex[i] - 1];

                // Adiciona os vértices e normais ao buffer de dados
                vboData.push_back(vertex.x);
                vboData.push_back(vertex.y);
                vboData.push_back(vertex.z);

                vboData.push_back(normal.x);
                vboData.push_back(normal.y);
                vboData.push_back(normal.z);
            }
        }
    }
    file.close();

    // Configuração dos buffers VAO e VBO
    glGenVertexArrays(1, &obj.VAO);
    glGenBuffers(1, &obj.VBO);

    glBindVertexArray(obj.VAO);
    glBindBuffer(GL_ARRAY_BUFFER, obj.VBO);
    glBufferData(GL_ARRAY_BUFFER, vboData.size() * sizeof(GLfloat), vboData.data(), GL_STATIC_DRAW);

    // Vértices (x, y, z)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    // Normais (nx, ny, nz)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    // Armazenar o número de vértices
    obj.nVertices = vboData.size() / 6;

    return 1;
}
