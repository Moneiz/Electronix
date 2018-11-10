#include "iConception.h"


int conception_update(SDL_Window* windowP, SDL_Renderer* rendererP, Surfaces_manager surfaceP){

    int i;
    int width, height;

    SDL_GetWindowSize(windowP,&width, &height);

    SDL_Rect background = {0, 0, width, height};
    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_RenderFillRect(rendererP,&background);

    //Dessine la grille de la page
    SDL_SetRenderDrawColor(rendererP,0,0,0,0);
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
    SDL_Rect text = {width/2, height/2, (*surfaceP.texts)->w, (*surfaceP.texts)->h};
    SDL_RenderCopy(rendererP,*textsTexP,NULL,&text);

    SDL_Rect textur = {width/4, height/4, (*surfaceP.images)->w / 4, (*surfaceP.images)->h / 4};
    SDL_RenderCopy(rendererP,*textureP,NULL,&textur);

    SDL_RenderPresent(rendererP);
}
//A isoler (complexité)
int destroyTextures(){
    int i;
    for(i = 0; i < sizeof(textureP) / sizeof(SDL_Texture*); i++){
        SDL_DestroyTexture(*(textureP+i));
    }
    free(textureP);
    for(i = 0; i < sizeof(textsTexP) / sizeof(SDL_Texture*); i++){
        SDL_DestroyTexture(*(textsTexP+i));
    }
    free(textsTexP);
    TTF_CloseFont(font);
}
