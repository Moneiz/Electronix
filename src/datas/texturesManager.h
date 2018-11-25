/**
* \file texturesManager.c
* \author Alan B.
* \version 1.0
* \date 25/11/2018
*
* Fichier contenant la structure du Textures_manager
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#ifndef TEXTURES_MANAGER_H
#define TEXTURES_MANAGER_H

/**
Structure organisant les textures
*/
typedef struct Textures_manager Textures_manager;
struct Textures_manager {

    /**Liste des textures d'image*/
    SDL_Texture** images;
    /**Liste des textures de texte*/
    SDL_Texture** texts;

};

#endif // TEXTURES_MANAGER_H
