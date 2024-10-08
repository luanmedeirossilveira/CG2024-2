//
// Created by Luanm on 16/09/2024.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int loadSimpleObj(const std::string& filePath, int &numVertices)
{
    int VAO;

    std::pmr::vector<GLfloat> vBuffer;

    std::ifstream arqEntrada(filePath, std::ios::binary);

    if (arqEntrada)
    {
        // Fazer parsing
        int numVerts = 0;

        std::string line;
        while (std::getline(arqEntrada, line))
        {
            if (line[0] == 'v')
            {
                ++numVerts;
                size_t start = 2;
                while (true)
                {
                    size_t end = line.find(' ', start);
                    if (end == std::string::npos) break;
                    vBuffer.push_back(std::stof(line.substr(start, end-start)));
                    start = end + 1;
                }
            }
        }

        numVertices = numVerts;

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VAO);
        glBufferData(GL_ARRAY_BUFFER, vBuffer.size() * sizeof(GLfloat), vBuffer.data(), GL_STATIC_DRAW);

        return 0;
    }
    else std::cout << "Failed to open file: " << filePath << std::endl;

    return 0;
}
