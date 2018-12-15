/**
* \file ressources.c
* \author Alan B.
* \version 1.6
* \date 12/12/2018
*
* Fichier qui gère l'intégralité des liens de ressources avant leur chargement en postInit
*/

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "datas/gridManager.h"

#include "modules/mGenerator.h"
#include "modules/mWires.h"
#include "modules/mResistor.h"
#include "modules/mCapacitor.h"

#ifndef RESSOURCES_H
#define RESSOURCES_H



#define NB_IMAGES 21
#define NB_TEXT 21


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
/**
Remplie la liste des modules
*/
void fillModuleList(Module* module);
#endif

