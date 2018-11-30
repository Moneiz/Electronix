#include "mWires.h"

void wire_drawComponent(SDL_Rect currentRect,Component currentComponent, int idTex,SDL_Renderer * rendererP,
                        SDL_Texture** textures){

    int state = currentComponent.stateModule;
    int angle = 0;

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
    }

    SDL_RenderCopyEx(rendererP,
                     textures[idTex],
                     NULL,
                     &currentRect,
                     angle,
                     NULL,
                     SDL_FLIP_HORIZONTAL);

}
