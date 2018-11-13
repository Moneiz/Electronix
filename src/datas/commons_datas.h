/**
* \file commons_datas.c
* \author Alan B.
* \version 1.0
* \date 12/11/2018
*
* Fichier contenant le patron du principale DTO du programme : Data
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "surfacesManager.h"
#include "texturesManager.h"

#ifndef DATAS_H
#define DATAS_H


/**
La structure Data contient des pointeurs vers
- le Surfaces_manager (accès aux surfaces chargés)
- le Textures_manager (accès aux textures chargés)
- le TTF_Font (accès à la police de caractères)
*/
typedef struct Datas Datas;
struct Datas {

    Surfaces_manager* surfaces;
    Textures_manager* textures;
    TTF_Font* font;

};

#endif // DATAS_H
