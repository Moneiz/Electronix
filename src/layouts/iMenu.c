#include "iMenu.h"

//TODO
//1. Mettre les déclarations de variables au début de la fonction
//2. Corriger le scintillement des éléments (le renderPresent est appelé qu'une fois)
//3. Ajouter le texte
//4. Réduire un peu la taille des boutons centraux en X
int menu_update(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas){

    int i;
    int width, height;

    int heightB, widthB; // Variables accueil

    SDL_GetWindowSize(windowP,&width, &height);

    // ACCUEIL
    widthB = width/2 - width/100;
    heightB = (height/2 - width/50)/3;

    //Dessine le fond
    SDL_Rect background = {0,0,width,height};
    SDL_RenderCopy(rendererP,datas.textures->images[7],NULL,&background);
    SDL_RenderPresent(rendererP);

    //Dessine le header
    SDL_SetRenderDrawColor(rendererP,21,51,54,0);
    SDL_Rect header = {0, height/9, width, height/7};
    SDL_RenderFillRect(rendererP, &header);

    //Texte Header

    //Dessine le menu
    SDL_SetRenderDrawColor(rendererP,160,253,255,0);
    SDL_Rect menu = {width/4, height/3, width/2, height/2};
    SDL_RenderFillRect(rendererP,&menu);


    //   !!!!!!FAIRE UNE BOUCLE FOR
    //Dessine le bouton niveaux
    SDL_SetRenderDrawColor(rendererP,21,51,54,0);
    SDL_Rect lvl = {width/4 + width/200, height/3 + width/200, widthB, heightB};
    SDL_RenderFillRect(rendererP,&lvl);

    //Texte Niveaux


    //Dessine le bouton conception
    SDL_SetRenderDrawColor(rendererP,21,51,54,0);
    SDL_Rect conception = {width/4 + width/200, height/3 + 2*width/200 + heightB, widthB, heightB};
    SDL_RenderFillRect(rendererP,&conception);

    //Texte Conception

    //Dessine le bouton quitter
    SDL_SetRenderDrawColor(rendererP,175,18,18,0);
    SDL_Rect quit = {width/4 + width/200, height/3 + 3*width/200 + 2*heightB, widthB, heightB};
    SDL_RenderFillRect(rendererP,&quit);

    //Dessine les credits
    SDL_SetRenderDrawColor(rendererP,17,17,17,0);
    SDL_Rect credits = {width/4, height/3 + height/2, width/2, height/10};
    SDL_RenderFillRect(rendererP,&credits);

    //Texte crédits


    SDL_RenderPresent(rendererP);

}


