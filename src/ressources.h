#include <stdio.h>
#include <stdlib.h>

#ifndef RESSOURCES_H
#define RESSOURCES_H

#define NB_IMAGES 1

/**
Strcture contenant toutes les ressources n�cessaire
au programme(lien image, son...)
*/
typedef struct Ressources {

    int sizeListImgFiles;
    char listImgFiles[NB_IMAGES][64];

} Ressources;

/**
Renvoie la structure Ressources avec les variables
affect�es
*/
Ressources getFilledRessources();


#endif