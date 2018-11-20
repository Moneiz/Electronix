#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>

#include "../datas/commons_datas.h"
#include "iMenu.h"

SDL_Texture** textureP;
SDL_Texture** textsTexP;
TTF_Font* font;

int conception_init(Datas *datas);
int conception_update(SDL_Window* windowP, SDL_Renderer* renderer, Datas datas);
int conception_event(SDL_Event event,SDL_Window* windowP,Datas *datas);
int conception_end(Datas datas);
