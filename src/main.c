#include <SDL2/SDL.h>
#include <stdio.h>

#include "kernel.h"
#include "ressources.h"
#include "datas/commons_datas.h"
#include "datas/surfacesManager.h"
#include "datas/texturesManager.h"
#include "config.h"

/**
*
* \file main.c
* \author Alan B., Sophie P.
* \version alpha-3
* \date 27/0.1/2019
*
* ELECTRONIX PROJECT
*
*/

int main(int argc, char** argv)
{
    SDL_Window* win;
    SDL_Renderer* render;

    Datas cDatas;

    //On charge les ressources (dont la configuration) du logiciel
    Ressources r = getFilledRessources("conf.ini");

    Surfaces_manager sm;
    Textures_manager tm;
    UI_manager uim;
    Grid_Manager gm;

    //On utilisera 10 modules qui seront initialisés et chargés
    cDatas.nbModules = 10;
    Module* modules = initModules(cDatas.nbModules);
    cDatas.modulesList = modules;

    //On assigne les différents managers du programme
    cDatas.surfaces = &sm;
    cDatas.textures = &tm;
    cDatas.ui = &uim;
    cDatas.grid = &gm;

    //On définit la version et le nom du projet utilisé dans le programme
    cDatas.version = "alpha-3";
    cDatas.projectName = "Electronix";

    //On essaye d'initialisé et ensuite de post-initialisé
    //avant de faire tourner le programme en boucle
    if(init(&win, &render,r) &  postInit(render, &cDatas,r)){
        updateApp(win, render, cDatas);
    }
    //La fin du programme détruit et désalloue ce qui a été alloué
    endApp(win, render, cDatas,r);
    freeModules(cDatas.modulesList);

    return 0;
}
