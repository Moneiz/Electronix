#include "gridHelper.h"

int* getNeighbourComponent(Datas* datas, Component* component){
    int cId[4];
    int i;
    int u = 0; //bug chelou ; à voir avec M. Sananes
    Component *componentsA[4];

    componentsA[0] = isEmpty(datas, component->posX, component->posY+1);
    componentsA[1] = isEmpty(datas, component->posX, component->posY-1);
    componentsA[2] = isEmpty(datas, component->posX+1, component->posY);
    componentsA[3] = isEmpty(datas, component->posX-1, component->posY);

    for(i = 0; i < 4;i++){
        cId[i] = componentsA[i] == NULL ? -1 : componentsA[i]->id;
        //printf("%d", cId[i]);
    }


    return cId;
}

void drawInfo(SDL_Renderer *renderer, SDL_Rect currentRect, Datas *datas,int value,char unity){
    int size  = currentRect.w;
    char buffer[5];
    int offset =0;
    SDL_Rect info = {
        currentRect.x,
        currentRect.y+size*0.1,
        size*0.6,
        size*0.2
    };
    if(value>=100) offset++;
    else if(value <10) offset--;
    itoa(value, buffer, 10);
    buffer[2+offset] = ' ';
    buffer[3+offset] = unity;
    buffer[4+offset] = '\0';
    redrawText(renderer, datas, 20, buffer,1);
    SDL_RenderCopy(renderer, datas->textures->texts[20], NULL, &info);
}

Component* isEmpty(Datas* datas, int x, int y){

    int i;
    for(i = 0; i < datas->grid->nbComponents; i++){
        if(datas->grid->components[i].posX == x &&
           datas->grid->components[i].posY == y
           && datas->grid->components[i].idModule != -1){
            return datas->grid->components + i;
           }
    }
    return NULL;

}
