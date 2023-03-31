#define GLEW_STATIC
#include "Render.hpp"

#include <cstdio>
#include <stdexcept>

#include "Window.hpp"

void Render::initRenderer(const uint32_t screenWidth, const uint32_t screenHeight,
                 const char *title)
{
    screen.initWindow(screenWidth, screenHeight, title);
    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("failed to initialize glew");
    }
    fprintf(stdout, "Status: Using GLEW %s \n", glewGetString(GLEW_VERSION));
    fprintf(stdout, "Status: Using OpenGL %s \n", glGetString(GL_VERSION));

    float positions[6] = {-0.5f, -0.5f, 0.5f, 0.5f, 0.5f, -0.5f};
    uint32_t buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    update();
    cleanup();
}

void Render::update() 
{ 
    while (!glfwWindowShouldClose(screen.window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(screen.window);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        screen.handleInput();
    }
}

void Render::cleanup() { screen.clean(); }
