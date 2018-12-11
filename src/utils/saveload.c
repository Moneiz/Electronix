#include "saveload.h"

int saveCircuit(char* filename, Datas datas){
    char path[255] = "./saves/";
    int result;
    strcat(path, filename);
    strcat(path, ".elc");

    FILE* file = fopen(path,"wb+");
    if(file != NULL){
        result = fwrite(datas.grid->components, sizeof(Component),datas.grid->nbComponents, file);
        //optimisation requise !
        fclose(file);
        return 1;
    }
    return 0;
}
int fileExist(char * filename){

    char path[255] = "./saves/";
    strcat(path, filename);
    strcat(path, ".elc");
    FILE* file = fopen(path,"rb");
    if(file == NULL){
        return 0;
    }
    fclose(file);
    return 1;

}
int loadCircuit(char* filename, Datas *datas){
    char path[255] = "./saves/";
    int result;
    int sizeFile;
    int nbComponent;
    strcat(path, filename);
    strcat(path, ".elc");

    FILE* file = fopen(path,"rb");
    if(file != NULL){
        fseek(file,0,SEEK_END);
        sizeFile = ftell(file);
        fseek(file,0, SEEK_SET);
        nbComponent = sizeFile/sizeof(Component);

        free(datas->grid->components);
        datas->grid->components = (Component*) malloc(sizeof(Component) * nbComponent);

        result = fread(datas->grid->components, sizeof(Component),nbComponent, file );
        datas->grid->nbComponents = nbComponent;

        fclose(file);
        return 1;
    }
    return 0;
}
