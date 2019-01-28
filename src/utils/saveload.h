/**
* \file saveload.c
* \author Alan B.
* \version 1.1
* \date 12/12/2018
*
* Fichier contenant les outils pour la gestion de la grille et de ces composants
*
*/
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include "listHelper.h"
#include "../datas/gridManager.h"
#include "../datas/commons_datas.h"

/** Remplie le tableau de char* result par le nom des fichiers sauvegardes présents dans le dossier save */
void getFileList(Datas *datas,char result[8][128]);

/** Enregistre dans le fichier filename la liste des composants */
int saveCircuit(char* filename, Datas datas);

/** Renvoie 1 si le fichier filename existe dans save */
int fileExist(Datas *datas, char * filename);

/** Charge la liste des composants depuis le fichier filename */
int loadCircuit(char* filename, Datas *datas);
