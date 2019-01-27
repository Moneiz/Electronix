#include "config.h"


char * subString(char * string, int start, int length){
    char * result;
    int i;

    //On alloue notre substring (+1 car '\0' pris en compte ! )
    result = (char*) malloc(sizeof(char)  * (length+1));

    //On copie notre chaine à partir de l'occurence donné
    //jusqu'à la taille saisie
    strncpy(result, string + start, length);

    //Dernier élément du tableau marque la fin de la chaine
    result[length] = '\0';

    return result;

}
void closeSubString(char * substring){
    //On ferme le substring alloué
    free(substring);
}
int boolToInt(char * booleanStr){
    //Si on a 'true', alors on renvoie 1 sinon 0
    return strcmp(booleanStr,"true") == 0 ? 1 : 0;
}
void lineToConfig(char * line, Config* config){

    char * key;
    char * value;
    char * splitSymbol;

    //On évite de prendre en compte le \n
    if(line[strlen(line)-1] == '\n'){
        line[strlen(line)-1] = '\0';
    }

    //Obtient l'adresse de la première occurence du symbole '='
    splitSymbol = strchr(line,'=');

    //Si la ligne n'a pas de '=', on annule l'analyse de la ligne
    if(splitSymbol == NULL){
        fprintf(stderr, "! Cannot configure :/ -> The config line '%s' was not understood. Ignored line !\n", line);
        return;
    }

    //Obtient la clé et la valeur avec les substrings sur le symbole
    key = subString(line,0,splitSymbol-line);
    value = subString(line, splitSymbol-line+1,strlen(line) - strlen(key) -1);

    //Selon la valeur de la clé, on configure selon la valeur
    if(strcmp(key,"fullscreen") == 0){
        config->fullscreen = boolToInt(value);
    }
    else if(strcmp(key,"maximized") == 0){
        config->maximized = boolToInt(value);
    }
    else if(strcmp(key,"width") == 0){
        config->width= atoi(value);
    }
    else if(strcmp(key,"height") == 0){
        config->height = atoi(value);
    }
    else if(strcmp(key,"savePath") == 0){
        strcpy(config->savesPath ,value);
    }
    else if(strcmp(key,"imgPath") == 0){
        strcpy(config->imgPath,value);
    }
    else if(strcmp(key,"fontsPath") == 0){
        strcpy(config->fontsPath,value);
    }
    else if(strcmp(key,"keyUpChoose") == 0){
        config->upChoose = getIntKeyFromStr(value);
    }
    else if(strcmp(key,"keyDownChoose") == 0){
        config->downChoose= getIntKeyFromStr(value);
    }
    else if(strcmp(key,"keyNavUp") == 0){
        config->navUp= getIntKeyFromStr(value);
    }
    else if(strcmp(key,"keyNavDown") == 0){
        config->navDown = getIntKeyFromStr(value);
    }
    else if(strcmp(key,"keyNavLeft") == 0){
        config->navLeft = getIntKeyFromStr(value);
    }
    else if(strcmp(key,"keyNavRight") == 0){
        config->navRigth= getIntKeyFromStr(value);
    }

    //On n'oublie pas de fermer les allocations dynamiques
    //causé par les substrings
    closeSubString(value);
    closeSubString(key);

}
int getIntKeyFromStr(char * str){
    //On transforme une valeur mise dans config
    //en valeur SDL_K compréhensible avec les
    //events
    if(strcmp(str,"LSHIFT") == 0)   return SDLK_LSHIFT;
    if(strcmp(str,"LCTRL") == 0)    return SDLK_LCTRL;
    if(strcmp(str,"UP") == 0)       return SDLK_UP;
    if(strcmp(str,"DOWN") == 0)     return SDLK_DOWN;
    if(strcmp(str,"LEFT") == 0)     return SDLK_LEFT;
    if(strcmp(str,"RIGHT") == 0)    return SDLK_RIGHT;
    //On pourra ajouter davantage selon besoin du client

    return 0;


}
Config initConf(char * confFilename){
    //Configuration par défaut
    //(si fichier ou ligne de config manquante)
    char curLine[256]="";
    FILE * file = NULL;
    Config configResult={
        1,
        0,
        1366,
        768,
        "./saves/",
        "./img",
        "./fonts/",
        SDLK_LSHIFT,
        SDLK_LCTRL,
        SDLK_UP,
        SDLK_DOWN,
        SDLK_LEFT,
        SDLK_RIGHT
    };

    //Ouvre le fichier config selon le chemin donné
    file = fopen(confFilename,"r");

    //Si le fichier a pu être ouvert
    if(file != NULL){

        //On itére chacune des lignes que l'on
        //traitera avec notre fonction lineToConfig
        //Elle changera la configuration selon l'information
        //de la ligne
        while(fgets(curLine, 1024, file)!=NULL){
            lineToConfig(curLine, &configResult);
        }

        fclose(file);
    }

    //On renvoie notre config
    return configResult;
}
