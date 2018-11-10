#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>

#include "surfacesManager.h"

SDL_Texture* textureP;
TTF_Font* font;


int initLayout(SDL_Renderer* renderer, Surfaces_manager surface);
int initTextures(SDL_Renderer* renderer, SDL_Surface** surface);

int update(SDL_Window* windowP, SDL_Renderer* renderer, Surfaces_manager surfaceP);
int destroyTextures();
