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
* \version pre-alpha-2.1
* \date 25/11/2018
*
* ELECTRONIX PROJECT
*
*/

int main(int argc, char** argv)
{
    SDL_Window* win;
    SDL_Renderer* render;

    Datas cDatas;

    Ressources r = getFilledRessources("conf.ini");

    Surfaces_manager sm;
    Textures_manager tm;
    UI_manager uim;
    Grid_Manager gm;

    cDatas.nbModules = 3;
    Module* modules = initModules(cDatas.nbModules);
    cDatas.modulesList = modules;

    cDatas.surfaces = &sm;
    cDatas.textures = &tm;
    cDatas.ui = &uim;
    cDatas.grid = &gm;

    cDatas.version = "pre-alpha-2.1";
    cDatas.projectName = "Electronix";

    if(init(&win, &render,r) &  postInit(render, &cDatas,r)){
        updateApp(win, render, cDatas);
    }
    endApp(win, render, cDatas,r);
    freeModules(cDatas.modulesList);

    return 0;
}
