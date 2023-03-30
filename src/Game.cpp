#include "Game.hpp"
#include "Window.hpp"

void Game::run(const uint32_t screenWidth, const uint32_t screenHeight, const char *title)
{
    screen.initWindow(screenWidth, screenHeight, title);
    mainLoop();
    cleanup();
}

void Game::mainLoop()
{
    screen.updateWindow();
}

void Game::cleanup()
{
    screen.clean();
}
