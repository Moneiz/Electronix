/**
* \file iConception.c
* \author Alan B.
* \date 12/12/2018
* \version 1.5
*
* Fichier qui gère la page de conception de circuit electrique
*/
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>

#include "../datas/commons_datas.h"
#include "iLevel.h"
#include "iMenu.h"
#include "iFileManager.h"
#include "../utils/uiEvent.h"
#include "../moduleLoader.h"
#include "../layoutLoader.h"
#include "../utils/listHelper.h"


/**
Obligatoire : Initialisation de la page (allocation des tableaux UI)
*/
int conception_init(Datas *datas);
/**
Obligatoire : Mise à jour du rendu de la page (affichage des éléments UI)
*/
int conception_update(SDL_Window* windowP, SDL_Renderer* renderer, Datas datas);

/** Mise à jour du rendu du header */
int conception_update_header(SDL_Renderer* rendererP, Datas datas, int width, int height);
/** Mise à jour du rendu du menu des modules */
int conception_update_modules(SDL_Renderer* rendererP, Datas datas, int width, int height);
/** Mise à jour du rendu du paramétres*/
int conception_update_parameters(SDL_Renderer* rendererP, Datas datas, int width, int height);
/**
Obligatoire : Mise à jour de la position des élements UI et écoute des évenements de ceux ci
*/
int conception_event(SDL_Event event,SDL_Window* windowP,SDL_Renderer* renderer,Datas *datas, int *running);
/**
Obligatoire : Destruction de la page (désallocation des tableaux UI)
*/
int conception_end(Datas *datas);

/** Détruis tous les composants de la grille */
int freeComponents(Datas *datas);
