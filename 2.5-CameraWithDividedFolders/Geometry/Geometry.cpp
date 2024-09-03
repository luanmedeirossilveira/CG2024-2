//
// Created by Luan Medeiros on 13/08/2024.
//

#include "Geometry.h"

// Implementação da função setupGeometry
int setupGeometry()
{
    GLfloat vertices[] = {
        //Base da pirâmide: 2 triângulos
        //x    y    z    r    g    b
        -0.5, -0.5, -0.5, 1.0, 1.0, 0.0,
        -0.5, -0.5,  0.5, 0.0, 1.0, 1.0,
         0.5, -0.5, -0.5, 1.0, 0.0, 1.0,

         -0.5, -0.5, 0.5, 1.0, 1.0, 0.0,
          0.5, -0.5,  0.5, 0.0, 1.0, 1.0,
          0.5, -0.5, -0.5, 1.0, 0.0, 1.0,

         -0.5, -0.5, -0.5, 1.0, 1.0, 0.0,
          0.0,  0.5,  0.0, 1.0, 1.0, 0.0,
          0.5, -0.5, -0.5, 1.0, 1.0, 0.0,

          -0.5, -0.5, -0.5, 1.0, 0.0, 1.0,
          0.0,  0.5,  0.0, 1.0, 0.0, 1.0,
          -0.5, -0.5, 0.5, 1.0, 0.0, 1.0,

           -0.5, -0.5, 0.5, 1.0, 1.0, 0.0,
          0.0,  0.5,  0.0, 1.0, 1.0, 0.0,
          0.5, -0.5, 0.5, 1.0, 1.0, 0.0,

           0.5, -0.5, 0.5, 0.0, 1.0, 1.0,
          0.0,  0.5,  0.0, 0.0, 1.0, 1.0,
          0.5, -0.5, -0.5, 0.0, 1.0, 1.0,
    };

    GLuint VBO, VAO;

    //Geração do identificador do VBO
    glGenBuffers(1, &VBO);

    //Faz a conexão (vincula) do buffer como um buffer de array
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //Envia os dados do array de floats para o buffer da OpenGl
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //Geração do identificador do VAO (Vertex Array Object)
    glGenVertexArrays(1, &VAO);

    // Vincula (bind) o VAO primeiro, e em seguida conecta e seta o(s) buffer(s) de vértices
    // e os ponteiros para os atributos
    glBindVertexArray(VAO);

    //Atributo posição (x, y, z)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)nullptr);
    glEnableVertexAttribArray(0);

    //Atributo cor (r, g, b)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    // Desvincula o VAO
    glBindVertexArray(0);

    return VAO;
}
