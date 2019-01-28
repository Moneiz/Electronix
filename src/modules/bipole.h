#include "SDL2/SDL.h"

#include "../datas/commons_datas.h"
#include "../datas/gridManager.h"
#include "../utils/gridHelper.h"

/** Dessine les composants classiques avec 2 bornes */
void bipole_drawComponent(SDL_Rect currentRect, Component currentComponent,int idTex,SDL_Renderer * rendererP,
                   Datas datas);
