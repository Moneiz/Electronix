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
* \version in-dev-7
* \date 17/11/2018
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
    Textures_manager tm;    //Déclaration de sm et tm

    cDatas.surfaces = &sm;
    cDatas.textures = &tm;  //Affectation de leur adresse dans
    //les valeurs de cDatas
    cDatas.version = "in-dev-7";
    cDatas.projectName = "Electronix";

    if(init(&win, &render,r) &  postInit(render, &cDatas,r)){
        updateApp(win, render, cDatas);
    }
    endApp(win, render, cDatas,r);

    return 0;
}
