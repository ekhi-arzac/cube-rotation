#include <SDL.h>
#include "Window.hpp"

int main(int argc, char* argv[])
{
    Window window;
    window.init(600, 600, (char*)"Cube Rotation");
    window.update();
    window.quit();

    return 0;
}