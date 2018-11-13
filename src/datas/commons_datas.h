#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "surfacesManager.h"
#include "texturesManager.h"

#ifndef DATAS_H
#define DATAS_H

typedef struct Datas Datas;
struct Datas {

    Surfaces_manager* surfaces;
    Textures_manager* textures;
    TTF_Font* font;

};

#endif // DATAS_H
