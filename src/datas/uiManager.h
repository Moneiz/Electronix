#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

typedef struct UI_manager UI_manager;
struct UI_manager {

    SDL_Rect * rectGroup;
    SDL_Rect * rectBt;

};

#endif // UI_MANAGER_H
