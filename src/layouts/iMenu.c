#include "iMenu.h"

int menu_update(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas){

    int width, height;

    SDL_GetWindowSize(windowP, &width, &height);

	SDL_Rect background = {0,0,width,height};
    SDL_Rect header = {0, height/9, width, height/7};
    SDL_Rect headerT = {(width - (height/7 - 20) * datas.surfaces->texts[0]->w/datas.surfaces->texts[0]->h)/2,
     height/9 + 10,
     (height/7 - 20) * datas.surfaces->texts[0]->w/datas.surfaces->texts[0]->h,
     height/7 - 20};

    SDL_Rect menu = {width/2 - width/8, height/3, width/4, height/2 - height/200};

    SDL_Rect creditsT = {width - width/4, height - height/30, width/4, height/30};

    SDL_RenderCopy(rendererP, datas.textures->images[7], NULL, &background);

    SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);
    SDL_RenderFillRect(rendererP, &header);
    SDL_RenderCopy(rendererP, datas.textures->texts[0], NULL, &headerT);

    SDL_SetRenderDrawColor(rendererP, 160, 253, 255, 0);
    SDL_RenderFillRect(rendererP, &menu);

    SDL_RenderCopy(rendererP, datas.textures->texts[5], NULL, &creditsT);

    menu_update_buttons(rendererP, datas, width, height);
    SDL_RenderPresent(rendererP);

 }

int menu_update_buttons(SDL_Renderer* rendererP, Datas datas, int width, int height){
	int counter, buttonX, buttonY, buttonW, buttonH, lines;
    SDL_Rect buttons[3];
    SDL_Rect buttonsT[3];

    lines = 3;

    buttonX = width/2 - width/8 + width/200;
    buttonY = height/3 + height/100;
    buttonW = (width/4 - 2 * width/200);
    buttonH = (height/2 - (lines + 1) * height/100)/lines;


    for(counter = 0; counter < 3; counter ++){
    	buttons[counter].x = buttonX;
    	buttons[counter].y = buttonY + counter * (height/100 + buttonH) ;
    	buttons[counter].w = buttonW;
    	buttons[counter].h = buttonH;

    	// Texte des boutons
    	buttonsT[counter].y = buttonY + counter * (height/100 + buttonH) + 30;
    	buttonsT[counter].h = buttonH - 60;
    	buttonsT[counter].w = buttonsT[counter].h * datas.surfaces->texts[counter + 1]->w / datas.surfaces->texts[counter + 1]->h;
        buttonsT[counter].x = buttonX + ( buttonW - buttonsT[counter].w)/2;

    	if(counter == 2){
    		SDL_SetRenderDrawColor(rendererP, 175, 18, 18, 0);
    	}else{
    		SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);
    	}
    	SDL_RenderFillRect(rendererP, &buttons[counter]);
    	SDL_RenderCopy(rendererP,datas.textures->texts[1 + counter],NULL, &buttonsT[counter]);
    }
}
