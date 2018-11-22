/**
* \file iMenu.c
* \author Sophie P.
* \date 22/11/2018
* \version 1.0
*
* Dessine le menu de choix des niveaux du mode didacticiel
*/

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>

#include "../datas/commons_datas.h"

int level_update(SDL_Window* windowP, SDL_Renderer* renderer, Datas datas);