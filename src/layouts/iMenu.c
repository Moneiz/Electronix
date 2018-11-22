#include "iMenu.h"

//TODO
//1. XXXMettre les déclarations de variables au début de la fonction
//2. XXX Corriger le scintillement des éléments (le renderPresent est appelé qu'une fois)
//3. Ajouter le texte
//4. Réduire un peu la taille des boutons centraux en X
int menu_update(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas){

    int width, height;

    SDL_GetWindowSize(windowP, &width, &height);

	SDL_Rect background = {0,0,width,height};
    SDL_Rect header = {0, height/9, width, height/7};
    SDL_Rect menu = {width/4, height/3, width/2, height/2 - height/200};
    SDL_Rect credits = {width/4, height/3 + height/2, width/2, height/10};

    SDL_RenderCopy(rendererP, datas.textures->images[7], NULL, &background);

    SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);
    SDL_RenderFillRect(rendererP, &header);

    SDL_SetRenderDrawColor(rendererP, 160, 253, 255, 0);
    SDL_RenderFillRect(rendererP, &menu);

    SDL_SetRenderDrawColor(rendererP, 17, 17, 17, 0);
    SDL_RenderFillRect(rendererP, &credits);

    menu_update_buttons(rendererP, datas, width, height);
    SDL_RenderPresent(rendererP);

 }

int menu_update_buttons(SDL_Renderer* rendererP, Datas datas, int width, int height){
	int counter, buttonX, buttonY, buttonW, buttonH, lines;
    SDL_Rect buttons[3];

    lines = 3;

    buttonX = width/4 + width/200;
    buttonY = height/3 + height/100;
    buttonW = (width/2 - 2 * width/200);
    buttonH = (height/2 - (lines + 1) * height/100)/lines;


    for(counter = 0; counter < 3; counter ++){
    	buttons[counter].x = buttonX;
    	buttons[counter].y = buttonY + counter * (height/100 + buttonH) ;
    	buttons[counter].w = buttonW;
    	buttons[counter].h = buttonH;
    	if(counter == 2){
    		SDL_SetRenderDrawColor(rendererP, 175, 18, 18, 0);
    	}else{
    		SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);
    	}
    	SDL_RenderFillRect(rendererP, &buttons[counter]);
    }
}
