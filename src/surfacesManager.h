#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#ifndef SURFACES_MANAGER_H
#define SURFACES_MANAGER_H

typedef struct Surfaces_manager {

    SDL_Surface** images;
    SDL_Surface** texts;
    TTF_Font* font;

} Surfaces_manager;

#endif // SURFACE_MANAGER_H
