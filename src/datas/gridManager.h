/**
* \file gridManager.c
* \author Alan B.
* \version 1.0
* \date 25/11/2018
*
* Fichier contenant la grille et ces propriétés
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#ifndef GRID_MANAGER_H
#define GRID_MANAGER_H
/**
Structure désignant un composant sur la grille
*/
typedef struct Component Component;
struct Component {
    unsigned short id;
    /**Position en X du composant*/
    unsigned short posX;
    /**Position en Y du composant*/
    unsigned short posY;
    /**Id du module pointé*/
    unsigned char idModule;

    /**Propriété du composant (tension, résistance, capacité...)*/
    float specificData;

    /**Etat du module (anticipé)*/
    unsigned char stateModule;
};
/**
Structure qui désigne la grille et ses propriétés
*/
typedef struct Grid_Manager Grid_Manager;
struct Grid_Manager {

    /**Niveau de zoom actuel*/
    int zoomLevel;
    /**Nombre de composant sur la grille*/
    int nbComponents;
    /**Liste des composants*/
    Component* components;

};

#endif // GRID_MANAGER_H
