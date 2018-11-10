#include "iConception.h"

int initLayout(SDL_Renderer* rendererP, Surfaces_manager surfaceP){

    if(!initTextures(rendererP, surfaceP.texts)){
        return 0;
    }
    if(!font){
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

int update(SDL_Window* windowP, SDL_Renderer* rendererP, Surfaces_manager surfaceP){

    int i;
    int width, height;

    SDL_GetWindowSize(windowP,&width, &height);

    //Dessine la grille de la page
    SDL_SetRenderDrawColor(rendererP,50,0,0,0);
    for(i = 0; i < height; i+=30){
        SDL_RenderDrawLine(rendererP, 0, i, width, i);
    }
    for(i = 0; i < width; i+=30){
        SDL_RenderDrawLine(rendererP, i, 0, i, height);
    }

    //Dessine le header de la page
    SDL_SetRenderDrawColor(rendererP,35,25,25,0);
    SDL_Rect headerB = {0, 0, width, height/8};
    SDL_RenderFillRect(rendererP,&headerB);
    SDL_SetRenderDrawColor(rendererP,10,10,10,0);
    SDL_Rect header = {5, 5, width-10, height/8-10};
    SDL_RenderFillRect(rendererP,&header);

    //Test sur la fenetre
    SDL_Rect background = {width/2, height/2, (*surfaceP.texts)->w, (*surfaceP.texts)->h};
    SDL_RenderCopy(rendererP,textureP,NULL,&background);
    SDL_RenderPresent(rendererP);

    //Test font
    SDL_Color color = {255,255,255};

    //SDL_RenderCopy(rendererP,*(surfaceP.texts),NULL,&background);

    SDL_RenderPresent(rendererP);
}

int destroyTextures(){
    SDL_DestroyTexture(textureP);
    TTF_CloseFont(font);
}
