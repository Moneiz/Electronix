#include <SDL2/SDL.h>
#include <stdio.h>

#include "kernel.h"
#include "ressources.h"
#include "surfacesManager.h"

int main(int argc, char** argv)
{
    SDL_Window* win;
    SDL_Renderer* render;

    Surfaces_manager sManager;

    Ressources r = getFilledRessources();


    if(init(&win, &render) &  postInit(render, &sManager,r)){
        updateApp(win, render, sManager);
    }
    endApp(win, render, sManager,r);

    return 0;
}
