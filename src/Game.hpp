#pragma once
#include <cstdint>
#include "Window.hpp"

class Game {
   public:
    void run(const uint32_t screenWidth, const uint32_t screenHeight, const char* title);
    void mainLoop();
    void cleanup();
private:
    Window screen;
};
