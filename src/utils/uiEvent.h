/**
* \file uiEvent.c
* \author Alan B.
* \version 1.0
* \date 25/11/2018
*
* Fichier contenant des fonctionnalités utiles pour gérer les évenements
* d'une interface
*/

#ifndef UI_EVENT

#define UI_EVENT

#include "../datas/commons_datas.h"
#include <SDL2/SDL.h>

/**
Obtient l'identifiant d'un bouton où
la position du curseur est dessus
*/
int getIdButtonOn(Datas datas, int xMouse, int yMouse);

/** Ecoute l'entrée des touches du clavier en le stockant dans filenameInputTxt */
int inputTxtListener(Datas * datas, SDL_Event event, int lenghtMax);

#endif // UI_EVENT
