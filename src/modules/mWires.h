#include "SDL2/SDL.h"

#include "../datas/commons_datas.h"
#include "../datas/gridManager.h"
#include "../utils/gridHelper.h"

/** @deprecated */
void wire_calculate(Component component,int src, Datas *datas);

/** Dessine un fil de cuivre */
void wire_drawComponent(SDL_Rect currentRect, Component currentComponent,int idTex,SDL_Renderer * rendererP,
               Datas datas);
