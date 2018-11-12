#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>

#include "layouts/iConception.h"
#include "datas/commons_datas.h"

int initLayout(SDL_Renderer* rendererP, Datas* datas);
int initTextures(SDL_Renderer* rendererP, Datas* datas);
int initTexsTex(SDL_Renderer* rendererP, Datas* datas);
int update(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas);
int destroyTextures(Datas datas);
