#include "Window.hpp"

#include <GLFW/glfw3.h>

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdexcept>

int Window::initWindow(const uint32_t screenWidth, const uint32_t screenHeight,
                       const char *title)
{
    if (!glfwInit()) {
        throw std::runtime_error("failed to initialize glfw");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(screenWidth, screenHeight, title, NULL, NULL);

    if (!window) {
        throw std::runtime_error("failed to create window");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    return EXIT_SUCCESS;
}


void Window::handleInput()
{
    glfwPollEvents();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void Window::clean()
{
    glfwDestroyWindow(window);
    glfwTerminate();
    std::cout << "cleaned glfw window" << std::endl;
}
