
#include "SDL2/SDL.h"

#include "../datas/commons_datas.h"
#include "../datas/gridManager.h"
#include "../utils/gridHelper.h"

/** @deprecated */
void generator_calculate(Component component, Datas *datas);
/** Dessine un générateur de courant continue */
void generator_drawComponent(SDL_Rect currentRect, Component currentComponent,int idTex,SDL_Renderer * rendererP,
                        Datas datas);
