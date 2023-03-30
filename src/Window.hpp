#pragma once
#include <GLFW/glfw3.h>

#include <cstdint>

class Window {
   public:
    int initWindow(const uint32_t screenWidth, const uint32_t screenHeight,
                   const char* title);
    void clean();
    void handleInput();
    void updateWindow();

   private:
    GLFWwindow* window;
};
