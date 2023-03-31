#pragma once
#include <GL/glew.h> 
#include <GL/gl.h>
#include <cstdint>
#include "Window.hpp"

class Render {
   public:
    void initRenderer(const uint32_t screenWidth, const uint32_t screenHeight, const char* title);
    void update();
    void cleanup();
private:
    Window screen;
};
