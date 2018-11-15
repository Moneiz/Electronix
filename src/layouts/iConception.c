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

    //Header
    conception_update_header(rendererP, datas, width,height);
    conception_update_modules(rendererP, datas,width, height);

    SDL_RenderPresent(rendererP);
}
int conception_update_header(SDL_Renderer* rendererP, Datas datas, int width, int height){

    //elements between marginX 0 width-marginX*2 height/8 !

    int i;
    int marginXHeader = width/2 - 0.2 * width;
    SDL_Rect headerB = {marginXHeader, 0, width-marginXHeader*2, height/8};
    SDL_Rect header = {marginXHeader + 5, 5, headerB.w -10, headerB.h-10};
    SDL_Rect currentBt = {header.x+10, header.y+10, header.w/5-20,header.h-20};
    SDL_Rect currentIcoBt = {currentBt.x+10,currentBt.y+10, currentBt.w-20, currentBt.h-20 };

    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_RenderFillRect(rendererP,&headerB);

    SDL_SetRenderDrawColor(rendererP,50,50,50,0);
    SDL_RenderFillRect(rendererP,&header);

    for(i = 0; i < 5; i++){
        currentBt.x = header.x+10  +header.w*i/5;
        SDL_RenderCopy(rendererP,datas.textures->images[5],NULL,&currentBt);
        currentIcoBt.x = currentBt.x +10;
        SDL_RenderCopy(rendererP,datas.textures->images[i],NULL,&currentIcoBt);

    }


}
int conception_update_modules(SDL_Renderer* rendererP, Datas datas, int width, int height){

    //elements between width-width/8 0 width/8 height !

    int i;
    SDL_Rect modulesB = {width-width/8, 0, width/8, height};
    SDL_Rect modules = {modulesB.x+5, 5, modulesB.w-10, modulesB.h-10};
    SDL_Rect currentMod = {modules.x+5, modules.y+5, modules.w -10, 20};

    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_RenderFillRect(rendererP,&modulesB);
    SDL_SetRenderDrawColor(rendererP,50,50,50,0);
    SDL_RenderFillRect(rendererP,&modules);

    for(i = 0; i < 8; i++){
        currentMod.y = modules.y + 5 +30*i;
        currentMod.h = 20;
        currentMod.w = currentMod.h*datas.surfaces->texts[i]->w / datas.surfaces->texts[i]->h;
        if(currentMod.w > modules.w - 10){
            currentMod.w = modules.w-10;
            //currentMod.h = datas.surfaces->texts[i]->w /(currentMod.w*datas.surfaces->texts[i]->h);
        }
        SDL_RenderCopy(rendererP,datas.textures->texts[i],NULL,&currentMod);
    }

}
