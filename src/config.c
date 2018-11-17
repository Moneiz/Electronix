#include "config.h"


char * subString(char * string, int start, int length){
    char * result = (char*) malloc(sizeof(char)  * (length+1));
    int i;
    strncpy(result, string + start, length);
    result[length] = '\0';
    return result;

}
void closeSubString(char * substring){
    free(substring);
}
int boolToInt(char * booleanStr){
    return strcmp(booleanStr,"true") == 0 ? 1 : 0;
}
void lineToConfig(char * line, Config* config){

    char * key;
    char * value;
    char * splitSymbol;

    if(line[strlen(line)-1] == '\n'){
        line[strlen(line)-1] = '\0';
    }

    splitSymbol = strchr(line,'=');
    if(splitSymbol == NULL){
        return;
    }
    key = subString(line,0,splitSymbol-line);
    value = subString(line, splitSymbol-line+1,strlen(line) - strlen(key) -1);

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
    closeSubString(value);
    closeSubString(key);

}
Config initConf(char * confFilename){
    Config configResult={1,0,1366,768};
    char curLine[256]="";
    FILE * file = NULL;

    file = fopen(confFilename,"r");

    if(file != NULL){

        while(fgets(curLine, 1024, file)!=NULL){
            lineToConfig(curLine, &configResult);
        }

        fclose(file);
    }
    return configResult;
}
