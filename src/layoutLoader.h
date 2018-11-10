#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>

#include "surfacesManager.h"
#include "layouts/iConception.h"

SDL_Texture** textureP;
SDL_Texture** textsTexP;
TTF_Font* font;

int initLayout(SDL_Renderer* rendererP, Surfaces_manager surfaceP);
int initTextures(SDL_Renderer* rendererP, SDL_Surface** surfaceP);
int initTexsTex(SDL_Renderer* rendererP, SDL_Surface** surfaceP);
int update(SDL_Window* windowP, SDL_Renderer* rendererP, Surfaces_manager surfaceP);
