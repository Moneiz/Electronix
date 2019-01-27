/**
* \file gridHelper.c
* \author Alan B.
* \version 1.0
* \date 09/12/2018
*
* Fichier contenant les outils pour la gestion de la grille et de ces composants
*
*/

#include "../datas/commons_datas.h"
#include "../datas/gridManager.h"
#include <SDL2/SDL.h>
/**Vérifie que l'emplacement x et y est libre*/
ItemComponent* isEmpty(Datas * datas, int x, int y);
void drawInfo(SDL_Renderer *renderer, SDL_Rect currentRect, Datas *datas,double value,char* unity);
int* getNeighbourComponent(Datas* datas, Component* component);
