#include "layoutLoader.h"

int initLayout(SDL_Renderer* rendererP, Surfaces_manager surfaceP){

    if(!initTextures(rendererP, surfaceP.images) |
       initTexsTex(rendererP, surfaceP.texts)){
        return 0;
    }
    return 1;
}
int initTextures(SDL_Renderer* rendererP, SDL_Surface** surfaceP){

    int i;
    int nbTex = sizeof(surfaceP) / sizeof(SDL_Surface*);
    textureP = malloc(sizeof(SDL_Texture*) * nbTex);

    for(i = 0; i < nbTex; i++){
        textureP[i] = SDL_CreateTextureFromSurface(rendererP,*surfaceP);
        if(!textureP[i]){
            fprintf(stderr,"Texture Creation Error :/ -> %s\n",SDL_GetError());
            return 0;
        }
    }
    return 1;
}
int initTexsTex(SDL_Renderer* rendererP, SDL_Surface** surfaceP){

    int i;
    int nbTex = sizeof(surfaceP) / sizeof(SDL_Surface*);
    textsTexP = malloc(sizeof(SDL_Texture*) * nbTex);

    for(i = 0; i < nbTex; i++){
        textsTexP[i] = SDL_CreateTextureFromSurface(rendererP,*surfaceP);
        if(!textsTexP[i]){
            fprintf(stderr,"Texts Creation Error :/ -> %s\n",SDL_GetError());
            return 0;
        }
    }
    return 1;
}
int update(SDL_Window* windowP, SDL_Renderer* rendererP, Surfaces_manager surfaceP){
    conception_update(windowP, rendererP, surfaceP);
}
