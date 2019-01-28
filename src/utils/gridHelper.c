#include "gridHelper.h"


void drawInfo(SDL_Renderer *renderer, SDL_Rect currentRect, Datas *datas,double value,char* unity){
    char buffer[7];
    SDL_Rect info = {
        currentRect.x-currentRect.w*0.9,
        currentRect.y-currentRect.h*0.65,
        currentRect.w*0.5,
        currentRect.h*0.3
    };
    sprintf(buffer, "%f", value);
    buffer[4] = ' ';
    buffer[5] = unity[0];
    buffer[6] = '\0';
    redrawText(renderer, datas, 20, buffer,1);
    SDL_SetRenderDrawColor(renderer,255,0,0,0);
    SDL_RenderDrawLine(renderer, currentRect.x+currentRect.w*0.1,
                           currentRect.y + currentRect.h*0.1,
                           currentRect.x-currentRect.w*0.3,
                           currentRect.y-currentRect.h*0.8);
    SDL_RenderDrawLine(renderer, currentRect.x-currentRect.w*0.3,
                           currentRect.y-currentRect.h*0.8,
                           currentRect.x-currentRect.w*0.9,
                           currentRect.y-currentRect.h*0.8);
    SDL_RenderCopy(renderer, datas->textures->texts[20], NULL, &info);
}

ItemComponent* isEmpty(Datas* datas, int x, int y){

    int i;
    ItemComponent * inter = datas->grid->components;
    for(i = 0; inter != NULL; i++){
        if(inter->component->posX == x &&
           inter->component->posY == y
           && inter->component->idModule != -1){
            return inter;
           }
        inter = inter->next;
    }
    return NULL;

}
