/**
* \file layoutLoader.c
* \author Alan B.
* \date 24/11/2018
* \version 1.3
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

int initLayouts(SDL_Renderer* rendererP, Datas* datas);
int initTextures(SDL_Renderer* rendererP, Datas* datas);
int initTexsTex(SDL_Renderer* rendererP, Datas* datas);
void redrawText(SDL_Renderer* rendererP, Datas* datas, int ptrText, char * newText);
int updateRender(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas);
void updateEvent(SDL_Event event,SDL_Window * windowP,SDL_Renderer * rendererP,  Datas * datas, int * running);
int destroyTextures(Datas datas);
