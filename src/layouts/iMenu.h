/**
* \file iMenu.c
* \author Sophie P.
* \date 15/11/2018
* \version 1.1
*
* Dessine le menu du programme
*/
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>

#include "../datas/commons_datas.h"
#include "iLevel.h"

#include "../utils/uiEvent.h"

#ifndef I_CONCEPTION_H
#define I_CONCEPTION_H

#include "iConception.h"

#endif // I_CONCEPTION_H




/**
Obligatoire : Initialisation de la page (allocation des tableaux UI)
*/
int menu_init(Datas *datas);
/**
Obligatoire : Mise à jour du rendu de la page (affichage des éléments UI)
*/
int menu_update(SDL_Window* windowP, SDL_Renderer* renderer, Datas datas);
/** Dessine les boutons représentants les niveaux */
int menu_update_buttons(SDL_Renderer* rendererP, Datas datas, int width, int height);
/**
Obligatoire : Mise à jour de la position des élements UI et écoute des évenements de ceux ci
*/
int menu_event(SDL_Event event,SDL_Window* windowP,SDL_Renderer* renderer,Datas *datas, int *running);
/**
Obligatoire : Destruction de la page (désallocation des tableaux UI)
*/
int menu_end(Datas *datas);
