//
// Created by Usuario on 23/07/2023.
//

#include "Window.hpp"
#include <SDL.h>

// Window and polygon setup
void Window::init(int height, int width, char* title) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    // CUBE
    pol.pushVtx(0,0,0); // 0
    pol.pushVtx(0,0,1); // 1
    pol.pushVtx(0,1,0); // 2
    pol.pushVtx(0,1,1); // 3
    pol.pushVtx(1,0,0); // 4
    pol.pushVtx(1,0,1); // 5
    pol.pushVtx(1,1,0); // 6
    pol.pushVtx(1,1,1); // 7
    // Settings
    pol.setOffset(1);

    pol.setSize(200);
    pol.distance = 200;

}
void Window::update()
{
    bool quit = false;
    while (!quit)
    {
        SDL_Delay(10);
        SDL_PollEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
                // TODO input handling code goes here
        }

        // clear window

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        // TODO rendering code goes here
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        draw();

        pol.rotateX(0.01);
        pol.rotateY(0.01);
        pol.rotateZ(0.01);

        // render window

        SDL_RenderPresent(renderer);
    }
}


void Window::quit()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// TODO implement adjacent point connection algorithm (graph theory)
void Window::draw() {
    // Cube demo
    SDL_RenderDrawLine(renderer, pol.vertices[0].x, pol.vertices[0].y, pol.vertices[1].x , pol.vertices[1].y);
    SDL_RenderDrawLine(renderer, pol.vertices[0].x, pol.vertices[0].y, pol.vertices[2].x , pol.vertices[2].y);
    SDL_RenderDrawLine(renderer, pol.vertices[0].x, pol.vertices[0].y, pol.vertices[4].x , pol.vertices[4].y);

    SDL_RenderDrawLine(renderer, pol.vertices[5].x, pol.vertices[5].y, pol.vertices[1].x , pol.vertices[1].y);
    SDL_RenderDrawLine(renderer, pol.vertices[5].x, pol.vertices[5].y, pol.vertices[4].x , pol.vertices[4].y);
    SDL_RenderDrawLine(renderer, pol.vertices[5].x, pol.vertices[5].y, pol.vertices[7].x , pol.vertices[7].y);


    SDL_RenderDrawLine(renderer, pol.vertices[3].x, pol.vertices[3].y, pol.vertices[1].x , pol.vertices[1].y);
    SDL_RenderDrawLine(renderer, pol.vertices[3].x, pol.vertices[3].y, pol.vertices[2].x , pol.vertices[2].y);
    SDL_RenderDrawLine(renderer, pol.vertices[3].x, pol.vertices[3].y, pol.vertices[7].x , pol.vertices[7].y);

    SDL_RenderDrawLine(renderer, pol.vertices[6].x, pol.vertices[6].y, pol.vertices[4].x , pol.vertices[4].y);
    SDL_RenderDrawLine(renderer, pol.vertices[6].x, pol.vertices[6].y, pol.vertices[2].x , pol.vertices[2].y);
    SDL_RenderDrawLine(renderer, pol.vertices[6].x, pol.vertices[6].y, pol.vertices[7].x , pol.vertices[7].y);
}
