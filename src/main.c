#include <SDL2/SDL.h>
#include <stdio.h>

#include "iConception.h"
#include "kernel.h"
#include "ressources.h"

int main(int argc, char** argv)
{
    SDL_Window* win;
    SDL_Renderer* render;
    SDL_Surface** surface;

    struct Ressources r = getFilledRessources();


    if(init(&win, &render) &  postInit(render, &surface,r)){
        updateApp(render, surface);
    }
    endApp(win, render, surface,r);

    return 0;
}
