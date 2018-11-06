#include <SDL2/SDL.h>
#include <stdio.h>

#include "iConception.h"
#include "kernel.h"

int main(int argc, char** argv)
{
    SDL_Window* win;
    SDL_Renderer* render;
    SDL_Surface* surface;


    if(init(&win, &render) &  postInit(render, &surface)){
        updateApp(render, surface);
    }
    endApp(win, render, surface);

    return 0;
}
