/**
* \file kernel.c
* \author Alan B
*\version 1.4.1
*\date 20/11/2018
*
* Fichier destiné à réunir les fonctionnalités complexes du programme
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h"
#include "datas/commons_datas.h"
#include "layoutLoader.h"
#include "layouts/iMenu.h"



/**
Fonction qui initialise la fenetre et renvoie un pointeur de ce
dernier. Si elle renvoie un NULL, l'initialisation a échoué.
*/
SDL_Window* initWindow();
/**
Fonction qui initialise le rendu grâce à la fenetre. Elle renvoie
un pointeur du rendu. Si elle renvoie un NULL, l'initialisation a
échoué.
*/
SDL_Renderer* initRenderer(SDL_Window* windowP);
/**
Fonction qui initialise l'utilisation des images JPG et PNG par SDL
dans le programme. Si elle renvoie 0, l'initialisation a échoué.
*/
int initImg();
/**
Fonction qui initialise l'utilisation des polices de caractères par
SDL dans le programme. Le renvoie de 0 signifie que l'initialisation
a échoué.
*/
int initTtf();


/**
Fonction qui initialise les outils de SDL et ses extensions nécessaires
au programme. Si elle renvoie 0, l'initialisation d'un composant a
échoué. Si tout ce passe bien, windowP et rendererP pointeront vers
une fenetre et un rendu.
*/
int init(SDL_Window** windowP, SDL_Renderer** rendererP, Ressources r);
/**
Fonction qui initialise l'ensemble des données à partir des ressources
de l'application. Les surfaces de datas (pour les textures et le text)
seront initialisé à partir des chemins de Ressources. Enfin, la fonction
appelle l'initilisation du layoutLoader. Si une initialisation de
ressources est impossible, alors le postInit renvoie 0
*/
int postInit(SDL_Renderer* rendererP, Datas* datas, Ressources r);
/**
Fonction à appeler après init et postInit qui permet de faire tourner en
boucle le programme pour le rendu et pour l'attente d'évenements.
*/
int updateApp(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas);
/**
Fonction qui désalloue l'intégrité des données DTO du programme (surfaces
et textures)
*/
void freeRessources(Datas datas , Ressources r);
/**
Fonction qui termine le programme : destruction des ressources puis
destruction du window et du rendu et fin de SDL et ses extensions.
*/
void endApp(SDL_Window* windowP, SDL_Renderer* rendererP,Datas datas, Ressources r);



int errMemoryUnalloc(int sizeByte);
