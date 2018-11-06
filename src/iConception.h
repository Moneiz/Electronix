#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

SDL_Texture* textureP;

int initLayout(SDL_Renderer* renderer, SDL_Surface* surface);
int initTextures(SDL_Renderer* renderer, SDL_Surface* surface);

int update(SDL_Renderer* renderer, SDL_Surface* surface);
int destroyTextures();
