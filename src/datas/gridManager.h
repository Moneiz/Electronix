#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#ifndef GRID_MANAGER_H
#define GRID_MANAGER_H

typedef struct Component Component;
struct Component {

    int posX;
    int posY;
    int idModule;
    int stateModule;

};

typedef struct Grid_Manager Grid_Manager;
struct Grid_Manager {

    int zoomLevel;
    int nbComponents;
    Component* components;

};

#endif // GRID_MANAGER_H
