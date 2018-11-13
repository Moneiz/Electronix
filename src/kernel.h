#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

#include "ressources.h"
#include "datas/commons_datas.h"
#include "layouts/iConception.h"
#include "layoutLoader.h"

char ** conf;

void initConf(char * confFilename); //Load conf file
SDL_Window* initWindow(); //Init window
SDL_Renderer* initRenderer(); //Init renderer
int initImg();
int initTtf();
int init(SDL_Window** windowP, SDL_Renderer** rendererP);
int postInit(SDL_Renderer* rendererP, Datas* datas, Ressources r);

int updateApp(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas);

void freeRessources(Datas datas , Ressources r);
void endApp(SDL_Window* windowP, SDL_Renderer* rendererP,Datas datas, Ressources r);
