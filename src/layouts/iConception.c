#include "iConception.h"


int conception_update(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas){

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
    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_Rect headerB = {0, 0, width, height/8};
    SDL_RenderFillRect(rendererP,&headerB);
    SDL_SetRenderDrawColor(rendererP,50,50,50,0);
    SDL_Rect header = {5, 5, width-10, height/8-10};
    SDL_RenderFillRect(rendererP,&header);

    //Test sur la fenetre
    SDL_Rect text = {width/2, height/2, datas.surfaces->texts[0]->w, datas.surfaces->texts[0]->h};
    SDL_RenderCopy(rendererP,datas.textures->texts[0],NULL,&text);

    SDL_Rect textur = {width/4, height/4, datas.surfaces->images[0]->w / 4, datas.surfaces->images[0]->h / 4};
    SDL_RenderCopy(rendererP,datas.textures->images[0],NULL,&textur);

    SDL_RenderPresent(rendererP);
}
