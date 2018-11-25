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

};
/**Fonction chargeant la configuration d'après le chemin
donné en paramètre*/
Config initConf(char * confFilename);

#endif // CONF_DEFINE
