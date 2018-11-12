#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>

#include "../datas/commons_datas.h"

SDL_Texture** textureP;
SDL_Texture** textsTexP;
TTF_Font* font;

int conception_update(SDL_Window* windowP, SDL_Renderer* renderer, Datas datas);
