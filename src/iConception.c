#include "iConception.h"

int initLayout(SDL_Renderer* rendererP, SDL_Surface** surfaceP){

    if(!initTextures(rendererP, surfaceP)){
        return 0;
    }
    return 1;
}
int initTextures(SDL_Renderer* rendererP, SDL_Surface** surfaceP){
    textureP = SDL_CreateTextureFromSurface(rendererP,*surfaceP);
    if(!textureP){
        fprintf(stderr,"Texture Creation Error :/ -> %s\n",SDL_GetError());
        return 0;
    }
    return 1;
}

int update(SDL_Renderer* rendererP, SDL_Surface** surfaceP){

    //SDL_Rect background = {640/2 - surfaceP->w/2, 480/2 - surfaceP->h/2, surfaceP->w, surfaceP->h};
    //SDL_RenderCopy(rendererP,textureP,NULL,&background);
    //SDL_RenderPresent(rendererP);
    SDL_SetRenderDrawColor(rendererP,255,0,0,0);
    int i, j;
    for(i = 0; i < 480; i+=30){
        SDL_RenderDrawLine(rendererP, 0, i, 640, i);
    }
    for(i = 0; i < 640; i+=30){
        SDL_RenderDrawLine(rendererP, i, 0, i, 480);
    }
    SDL_RenderPresent(rendererP);
}

int destroyTextures(){
    SDL_DestroyTexture(textureP);
}
