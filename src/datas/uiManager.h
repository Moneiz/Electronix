/**
* \file uiManager.c
* \author Alan B.
* \version 1.0
* \date 25/11/2018
*
* Fichier contenant la structure du UI_manager
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

/**Strcture contenant les différents éléments UI
de l'interface actuelle*/
typedef struct UI_manager UI_manager;
struct UI_manager {

    /**Nombre de boutons total*/
    int nbBt;
    /**Liste des groupes design*/
    SDL_Rect * rectGroup;
    /**Liste des boutons*/
    SDL_Rect * rectBt;

};

#endif // UI_MANAGER_H
