#include "mWires.h"

void wire_calculate(Component component,int src, Datas *datas){



}

void wire_drawComponent(SDL_Rect currentRect,Component currentComponent, int idTex,SDL_Renderer * rendererP,
                       Datas datas){

    int state = currentComponent.stateModule;
    int angle = 0;
    int color;

    switch(state){
        case 1: angle = 90;
            break;
        case 2: idTex = 11;     angle = 0;
            break;
        case 3: idTex = 11;     angle = 90;
            break;
        case 4: idTex = 11;     angle = 180;
            break;
        case 5: idTex = 11;     angle = 270;
            break;
        case 6: idTex = 13;     angle = 0;
            break;
        case 7: idTex = 13;     angle = 90;
            break;
        case 8: idTex = 13;     angle = 180;
            break;
        case 9: idTex = 13;     angle = 270;
            break;
        case 10: idTex = 14;
            break;
        default:
            break;
    }/* Temps réel - annulé
    if(datas.realTimeEnable){
        color = 255/(-0.3*abs(currentComponent.voltage) - 1) +255;
        color = currentComponent.voltage < 0 ? -color/2+128 : color/2 +128;

        SDL_SetTextureColorMod(datas.textures->images[idTex], color,0 ,255-color);
    }*/
    SDL_RenderCopyEx(rendererP,
                     datas.textures->images[idTex],
                     NULL,
                     &currentRect,
                     angle,
                     NULL,
                     SDL_FLIP_HORIZONTAL);
    if(datas.realTimeEnable)
        SDL_SetTextureColorMod(datas.textures->images[idTex], 255,255,255);
}
