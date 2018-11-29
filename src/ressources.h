/**
* \file ressources.c
* \author Alan B.
* \version 1.3
* \date 24/11/2018
*
* Fichier qui gère l'intégralité des liens de ressources avant leur chargement en postInit
*/

#include <stdio.h>
#include <stdlib.h>

#include "config.h"

#ifndef RESSOURCES_H
#define RESSOURCES_H



#define NB_IMAGES 12
#define NB_TEXT 9


/**
Strcture contenant toutes les ressources nécessaire
au programme(lien image, son...)
*/
typedef struct Ressources Ressources;
struct Ressources {

    Config config;
    int sizeListImgFiles;
    char listImgFiles[NB_IMAGES][64];
    int sizeListText;
    char listText[NB_TEXT][64];
    char font[255];
    char appVersion[32];

};


/**
Renvoie la structure Ressources avec les variables
affectées
*/
Ressources getFilledRessources(char * configFile);


#endif
