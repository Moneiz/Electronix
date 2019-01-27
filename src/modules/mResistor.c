#include "mResistor.h"

void valueToColor(int color[4], float resistor);

void resistor_drawComponent(SDL_Rect currentRect,Component currentComponent, int idTex,SDL_Renderer * rendererP,
                        Datas datas){

    int size = currentRect.w;
    SDL_Rect currentColorBar = {size*0.25+ currentRect.x,
        size*0.43 + currentRect.y,
        size*0.075,
        size*0.17};
    int state = currentComponent.stateModule;
    float resistor = currentComponent.specificData;
    int listColor[4];
    int angle = 0;
    int i;
    char buffer[6];

    //Applique les états
    switch(state){
        case 1: angle = 90;
            turnInfo(size,currentRect, &currentColorBar);
            break;
        default:
            break;
    }

    //Dessine le symbole de la résistance
    SDL_RenderCopyEx(rendererP,
                     datas.textures->images[idTex],
                     NULL,
                     &currentRect,
                     angle,
                     NULL,
                     SDL_FLIP_HORIZONTAL);

    //Dessine les codes couleurs sur la résistance
    valueToColor(listColor, resistor);
    for(i = 0; i<4;i++){
        setColorFromInt(rendererP, listColor[i]);
        SDL_RenderFillRect(rendererP, &currentColorBar);
        if(angle == 0){
            if(i == 2) currentColorBar.x += size*0.15;
            currentColorBar.x += size*0.1;
        }else{
            if(i == 2) currentColorBar.y += size*0.15;
            currentColorBar.y += size*0.1;
        }
    }
    if(datas.grid->selectedComponent != currentComponent.id) return;
    drawInfo(rendererP, currentRect, &datas,currentComponent.specificData, "O");

}

void turnInfo(int size, SDL_Rect currentComp ,SDL_Rect *bar){

    *bar = (SDL_Rect) {
        size*0.4 + currentComp.x,
        size*0.25+ currentComp.y,
        size*0.2,
        size*0.075};


}

void setColorFromInt(SDL_Renderer* renderP, int colorCode){
    int r,g,b;
    switch(colorCode){
        case 0:
            r=0;    g=0;    b=0;
            break;
        case 1:
            r=100;  g=40;   b=0;
            break;
        case 2:
            r=255;  g=0;    b=40;
            break;
        case 3:
            r=255;  g=176;  b=0;
            break;
        case 4:
            r=239;  g=239;  b=0;
            break;
        case 5:
            r=0;    g=166;  b=32;
            break;
        case 6:
            r=51;   g=102;  b=255;
            break;
        case 7:
            r=160;  g=0;    b=160;
            break;
        case 8:
            r=143;  g=143;  b=143;
            break;
        case 9:
            r=255;  g=255;  b=255;
            break;
        case 10:
            r=211;  g=203;  b=16;
            break;
        case 11:
            r=207;  g=207;  b=207;
            break;
        default:
            r=0;    g=0;    b=0;
            break;
    }

    SDL_SetRenderDrawColor(renderP,r,g,b,255);

}

void valueToColor(int color[4], float resistor){

    float rest=resistor;
    int power = 0;

    while(rest>=100){
        rest/=10;
        power++;
    }
    while(rest<10){
        rest*=10;
        power--;
    }

    if(power > 9) power=9;
    if(power<-2) power=-2;

    color[0] = rest/10;
    color[1] = (int)(rest)%10;
    color[2] = power >= 0 ? power : 9-power;
    color[3] = 10;

    return color;

}
