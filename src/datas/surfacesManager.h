/**
* \file surfacesManager.c
* \author Alan B.
* \version 1.0
* \date 25/11/2018
*
* Fichier contenant la structure de Surfaces_Manager
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#ifndef SURFACES_MANAGER_H
#define SURFACES_MANAGER_H

/**
Structure organisant les SDL_Surface
*/
typedef struct Surfaces_manager Surfaces_manager;
struct Surfaces_manager {

    /**Surface des images*/
    SDL_Surface** images;
    /**Surface des textes*/
    SDL_Surface** texts;
    /**Nombre d'image*/
    int nbImg;
    /**Nombre de texte*/
    int nbText;

};

#endif // SURFACE_MANAGER_H
