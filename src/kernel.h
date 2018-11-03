#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

char ** conf;
SDL_Window* windowP;
SDL_Renderer* rendererP;

void initConf(char * confFilename); //Load conf file
SDL_Window* initWindow(); //Init window
//SDL_Renderer* initRenderer(); //Init renderer

int updateApp();

void endApp();
