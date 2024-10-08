//
// Created by Luan Medeiros on 13/08/2024.
// Edited by Luan Medeiros on 02/09/2024.
//

#include "Callbacks.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

extern bool rotateX, rotateY, rotateZ;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // Movimentos da camera
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    float cameraSpeed = 0.05f;

    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        cameraPos += cameraSpeed * cameraFront;
    }
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
    {
        cameraPos -= cameraSpeed * cameraFront;
    }
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
    {
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    {
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }
}
