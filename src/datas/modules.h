/**
* \file modules.h
* \author Alan B.
* \version 1.1
* \date 30/11/2018
*
* Fichier contenant la structure d'un module
*/

#include "SDL2/SDL.h"
#include "gridManager.h"

#ifndef MODULE_LOADER
#define MODULE_LOADER

/**
Structure d'un module
*/
typedef struct Module Module;
struct Module{

    /**
    \deprecated

    Id du module*/
    int id;
    /**Id de la texture du texte associée*/
    int idTextTex;
    /**Id de la texture icone associée*/
    int idTex;
    /**Pointeur de fonction vers la fonction de rendu*/
    void (*ptrFctRender)(SDL_Rect,Component, int,SDL_Renderer *, SDL_Texture**);

};

#endif // MODULE_LOADER
