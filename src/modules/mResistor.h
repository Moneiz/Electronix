#include "SDL2/SDL.h"

#include "../datas/commons_datas.h"
#include "../datas/gridManager.h"
#include "../utils/gridHelper.h"

/** Dessine une résistance */
void resistor_drawComponent(SDL_Rect currentRect, Component currentComponent,int idTex,SDL_Renderer * rendererP,
                   Datas datas);
/** Gére le dessin de la résistance quand la résistance est à 90°  */
void turnInfo(int size, SDL_Rect currentComp ,SDL_Rect *bar);

/** Définie la couleur d'après le code couleur */
void setColorFromInt(SDL_Renderer* renderP, int colorCode);
