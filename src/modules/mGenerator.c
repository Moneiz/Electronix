#include "mGenerator.h"

void generator_calculate(Component component, Datas *datas){
    int i;
    int nb = 1;
    int* neighbour = getNeighbourComponent(datas, &component);
    for(i = 0; i < 4; i++){
        if(neighbour[i] != -1 && nb == 1){
            nb++;
            wire_calculate(datas->grid->components[neighbour[i]],component.id, datas);
        }
    }

}
void generator_drawComponent(SDL_Rect currentRect,Component currentComponent, int idTex,
        SDL_Renderer * rendererP,Datas datas){

    int state = currentComponent.stateModule;
    int angle = 0;
    int voltage = currentComponent.specificData;

    switch(state){
        case 1: angle = 270;
            break;
        default:
            break;
    }

    SDL_RenderCopyEx(rendererP,
                     datas.textures->images[idTex],
                     NULL,
                     &currentRect,
                     angle,
                     NULL,
                     SDL_FLIP_HORIZONTAL);
    drawInfo(rendererP, currentRect, &datas,5, 'V');
}
