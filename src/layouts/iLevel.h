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
#include "../utils/uiEvent.h"

#ifndef I_LEVEL_H
#define I_LEVEL_H
#include "iMenu.h"
#endif // I_LEVEL_H

/**
Obligatoire : Initialisation de la page (allocation des tableaux UI)
*/
int level_init(Datas *datas);
/**
Obligatoire : Mise à jour du rendu de la page (affichage des éléments UI)
*/
int level_update(SDL_Window* windowP, SDL_Renderer* renderer, Datas datas);
/**
Obligatoire : Mise à jour de la position des élements UI et écoute des évenements de ceux ci
*/
int level_event(SDL_Event event,SDL_Window* windowP,SDL_Renderer* renderer,Datas *datas, int *running);
/**
Obligatoire : Destruction de la page (désallocation des tableaux UI)
*/
int level_end(Datas *datas);
