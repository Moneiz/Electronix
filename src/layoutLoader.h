/**
* \file layoutLoader.c
* \author Alan B.
* \date 25/11/2018
* \version 1.4
*
* Ce fichier gère le lien entre le kernel et les différentes
* interfaces du programme
*/

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>

#include "layouts/iConception.h"
#include "layouts/iMenu.h"
#include "datas/commons_datas.h"

/**
Fonction appelé afin d'initialiser le layout
*/
int initLayouts(SDL_Renderer* rendererP, Datas* datas);
/**
Fonction permettant de créer les textures à partir des images
Requiert l'initialisation des surfaces des images dans Datas
*/
int initTextures(SDL_Renderer* rendererP, Datas* datas);
/**
Fonction permettant de créer les textures à partir des textes
Requiert l'initialisation des surfaces des textes dans Datas
*/
int initTexsTex(SDL_Renderer* rendererP, Datas* datas);
/**
Fonction permettant de modifier un texte en repétant les étapes de mise
en texture
*/
void redrawText(SDL_Renderer* rendererP, Datas* datas, int ptrText, char * newText);
/**
Fonction mettant à jour le rendu selon l'interface de rendu pointée
*/
int updateRender(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas);
/**
Fonction mettant à jour les évènements selon l'interface d'évènement pointée
*/
void updateEvent(SDL_Event event,SDL_Window * windowP,SDL_Renderer * rendererP,  Datas * datas, int * running);
/**
Fonction appelé afin de détruire les textures de Datas
*/
int destroyTextures(Datas datas);
