#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "ressources.h"

char ** conf;

void initConf(char * confFilename); //Load conf file
SDL_Window* initWindow(); //Init window
SDL_Renderer* initRenderer(); //Init renderer
int initImg();
int init(SDL_Window** windowP, SDL_Renderer** rendererP);
int postInit(SDL_Renderer* rendererP, SDL_Surface*** surfaceP, Ressources r);

int updateApp(SDL_Window* windowP, SDL_Renderer* rendererP, SDL_Surface** surfaceP);

void freeRessources(SDL_Surface** surfaceP, Ressources r);
void endApp(SDL_Window* windowP, SDL_Renderer* rendererP,SDL_Surface** surfaceP, Ressources r);
