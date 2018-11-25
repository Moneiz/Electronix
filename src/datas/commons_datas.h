/**
* \file commons_datas.c
* \author Alan B.
* \version 1.3
* \date 24/11/2018
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
La structure Data contient des pointeurs vers
- le Surfaces_manager (accès aux surfaces chargés)
- le Textures_manager (accès aux textures chargés)
- le UI_Manager (accès aux UI)
- le TTF_Font (accès à la police de caractères)
- les infos du projet (version et nom du projet)
- pointeurs des rendus et events updater
*/
typedef struct Datas Datas;
struct Datas {

    //Managers
    Surfaces_manager* surfaces;
    Textures_manager* textures;
    UI_manager* ui;
    Grid_Manager* grid;

    //Module
    Module* modulesList;
    int nbModules;
    int idSel;

    //Project infos
    char *version;
    char *projectName;

    //Pointeur de fonction des updateurs
    int (*currentIRenderFct)(SDL_Window *,SDL_Renderer *, Datas);
    int (*currentIEventsFct)(SDL_Event, SDL_Window*, SDL_Renderer*, Datas*);

    //Special
    TTF_Font* font;
};

#endif // DATAS_H
