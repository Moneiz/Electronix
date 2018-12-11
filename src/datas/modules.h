/**
* \file modules.h
* \author Alan B.
* \version 1.2
* \date 10/12/2018
*
* Fichier contenant la structure d'un module
*/

#include "SDL2/SDL.h"
#include "gridManager.h"

#ifndef MODULE_LOADER
#define MODULE_LOADER

#include "commons_datas.h"
typedef struct Datas Datas;
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
    /**Nombre de liaison*/
    int nbLink;

    /**Pointeur de fonction vers la fonction de rendu*/
    void (*ptrFctRender)(SDL_Rect,Component, int,SDL_Renderer *, Datas);
    /**Pointeur de fonction vers la fonction de calcul*/
    void (*ptrFctCalculate)(Component,Datas);

};
#endif // MODULE_LOADER


