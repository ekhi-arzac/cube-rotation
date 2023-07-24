#ifndef CUBE_ROTATION_WINDOW_HPP
#define CUBE_ROTATION_WINDOW_HPP
#include <SDL.h>
#include "Polyhedron.hpp"

class Window {
public:
    Polyhedron pol;

    SDL_Event event;
    SDL_Window * window;
    SDL_Renderer * renderer;

    void init(int height, int width, char* title);
    void update();
    void quit();

    void draw();
};


#endif //CUBE_ROTATION_WINDOW_HPP
