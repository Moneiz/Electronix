/**
* \file config.c
* \author Alan B.
* \version 1.0
* \date 25/11/2018
*
* Fichier gérant la configuration du programme
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL2/SDL.h"

#ifndef CONF_DEFINE
#define CONF_DEFINE

/**
Strcture contenant la configuration du programme
*/
typedef struct Config Config;
struct Config {

    /**Ordre 1 : Plein écran*/
    int fullscreen;
    /**Ordre 2 : Application fenetré avec taille maximale*/
    int maximized;
    /**Ordre 3 : Largeur de l'application fenetrée */
    int width;
    /**Ordre 3 : Hauteur de l'application fenetrée */
    int height;
    /** Chemin des sauvegardes */
    char savesPath[64];
    /** Chemin des ressources images */
    char imgPath[64];
    /** Chemin des polices */
    char fontsPath[64];

    int upChoose;
    int downChoose;
    int navUp;
    int navDown;
    int navLeft;
    int navRigth;

};
/**Fonction chargeant la configuration d'après le chemin
donné en paramètre*/
Config initConf(char * confFilename);

/** Récupère le code SDLK à partir d'un IDNAME d'une touche du clavier */
int getIntKeyFromStr(char * str);
#endif // CONF_DEFINE
