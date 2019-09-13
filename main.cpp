#include <iostream>
#include <stdio.h>
#include "Version.h"
#include "foo.h"
#include <GL/glew.h>

#if defined(__APPLE__)

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

using namespace std;

int main() {
    fprintf(stdout,
            "Hello from version: %d.%d\n",
            opengl_learning_VERSION_MAJOR,
            opengl_learning_VERSION_MINOR);

    glewExperimental = true;

    if (!glfwInit()) {
        fprintf(stdout, "Failed to initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window;
    window = glfwCreateWindow(1024, 769, "My first window", NULL, NULL);

    if (window == NULL) {
        fprintf(stdout, "Unable to open GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        fprintf(stdout, "Unable to initialize GLEW\n");
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
    glfwWindowShouldClose(window) == 0);

    return 0;
}