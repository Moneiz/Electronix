#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#ifndef TEXTURES_MANAGER_H
#define TEXTURES_MANAGER_H

typedef struct Textures_manager Textures_manager;
struct Textures_manager {

    SDL_Texture** images;
    SDL_Texture** texts;

};

#endif // TEXTURES_MANAGER_H
