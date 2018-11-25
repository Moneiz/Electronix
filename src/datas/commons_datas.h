/**
* \file commons_datas.c
* \author Alan B.
* \version 1.4
* \date 25/11/2018
*
* Fichier contenant le patron du principale DTO du programme : Data
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


#include "surfacesManager.h"
#include "texturesManager.h"
#include "uiManager.h"
#include "gridManager.h"
#include "modules.h"

#ifndef DATAS_H
#define DATAS_H

/**
La structure Datas est le DTO principal du programme
*/






typedef struct Datas Datas;
struct Datas {

    /**Accès aux surfaces chargés*/
    Surfaces_manager* surfaces;
    /**Accès aux textures chargés*/
    Textures_manager* textures;
    /**Accès aux UI*/
    UI_manager* ui;
    /**Accès à la grille*/
    Grid_Manager* grid;

    /**Liste des modules*/
    Module* modulesList;
    /**Nombre de module*/
    int nbModules;
    /**Module actuellement sélectionné*/
    int idSel;

    /**Version du projet*/
    char *version;
    /**Nom du projet*/
    char *projectName;

    /**Pointeur vers la fonction de rendu actuelle*/
    int (*currentIRenderFct)(SDL_Window *,SDL_Renderer *, Datas);
    /**Pointeur vers la fonction des évènements actuelle*/
    int (*currentIEventsFct)(SDL_Event, SDL_Window*, SDL_Renderer*, Datas*);

    /**Police de texte du programme*/
    TTF_Font* font;
};

#endif // DATAS_H
