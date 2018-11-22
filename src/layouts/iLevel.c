#include "iLevel.h"

int level_update(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas){

    int width, height;

    SDL_GetWindowSize(windowP, &width, &height);

	SDL_Rect background = {0,0,width,height};
    SDL_Rect header = {0, height/9, width, height/7};
    SDL_Rect menu = {width/4, height/3, width/2 - width/200, height/2 - height/200};
    
    SDL_RenderCopy(rendererP, datas.textures->images[7], NULL, &background);

    SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);
    SDL_RenderFillRect(rendererP, &header);

    SDL_SetRenderDrawColor(rendererP, 160, 253, 255, 0);
    SDL_RenderFillRect(rendererP, &menu);

    level_update_buttons(rendererP, datas, width, height);
    SDL_RenderPresent(rendererP);

 }

int level_update_buttons(SDL_Renderer* rendererP, Datas datas, int width, int height){
   int counterI, counterJ, buttonX, buttonY, buttonW, buttonH, columns, lines;;
    SDL_Rect buttons[3][5];

    columns = 5;
    lines = 3;
    buttonX = width/4 + width/200;
    buttonY = height/3 + height/100;    
    buttonW = (width/2 - (columns + 1) * width/200)/columns;
    buttonH = (height/2 - (lines + 1) * height/100)/lines;

    for(counterI = 0; counterI < 3; counterI ++){
        for(counterJ = 0; counterJ < 5; counterJ ++){
            buttons[counterI][counterJ].x = buttonX + counterJ * (height/100 + buttonW);
            buttons[counterI][counterJ].y = buttonY + counterI * (width/200 + buttonH) ;
            buttons[counterI][counterJ].w = buttonW;
            buttons[counterI][counterJ].h = buttonH;
            SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);
            SDL_RenderFillRect(rendererP, &buttons[counterI][counterJ]);
        }
    }
}