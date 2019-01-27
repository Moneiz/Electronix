#include "saveload.h"

int saveCircuit(char* filename, Datas datas){
    char path[255];
    int result;
    strcpy(path, datas.config.savesPath);
    strcat(path, filename);
    strcat(path, ".elc");

    FILE* file = fopen(path,"wb+");
    if(file != NULL){
        result = fwrite(datas.grid->components, sizeof(Component),datas.grid->nbComponents, file);
        //optimisation requise !
        fprintf(stdout, "Electronix has saved %d components to %s.elc successfully!\n", datas.grid->nbComponents, filename);
        fclose(file);

        return 1;
    }
    fprintf(stderr, "! File Unwritable :/ -> %s.elc was not be created. Cancelled save !\n", filename);
    return 0;
}

void getFileList(Datas *datas,char result[8][128]){
    DIR *d;
    int nbFile;
    struct dirent *dir;
    char generalName[128];
    int counter =0;
    d = opendir(datas->config.savesPath);
    if(d){
        while((dir = readdir(d)) != NULL){
            if(strlen(dir->d_name) > 4){
                strncpy(generalName,dir->d_name, strlen(dir->d_name) - 4);
                generalName[strlen(dir->d_name)-4] = '\0';
                if(fileExist(datas, generalName) && counter < 8){
                    strcpy(result[counter++], generalName);
                }
            }
        }
        closedir(d);
    }
    fprintf(stderr, "! Folder Not Found :/ -> %s was not found as folder. Cancelled operation !\n", datas->config.savesPath);

    for( ; counter < 8; counter++){
        result[counter][0] = '\0';
    }

    return result;
}

int fileExist(Datas *datas, char * filename){

    char path[255];
    strcpy(path, datas->config.savesPath);
    strcat(path, filename);
    strcat(path, ".elc");
    FILE* file = fopen(path,"rb");
    if(file == NULL){
        fprintf(stderr, "! File Not Found :/ -> %s.elc was not found !\n", filename);
        return 0;
    }
    fclose(file);
    return 1;

}
int loadCircuit(char* filename, Datas *datas){
    char path[255];
    int result;
    int sizeFile;
    int nbComponent;
    strcpy(path, datas->config.savesPath);
    strcat(path, filename);
    strcat(path, ".elc");

    FILE* file = fopen(path,"rb");
    if(file != NULL){
        fseek(file,0,SEEK_END);
        sizeFile = ftell(file);
        fseek(file,0, SEEK_SET);
        nbComponent = sizeFile/sizeof(Component);

        if(nbComponent == 0){
            fprintf(stderr, "! File Is Empty :/ -> %s.elc is empty file. Cancelled opening !\n", filename);
            fclose(file);
            return 0;
        }

        free(datas->grid->components);
        datas->grid->components = (Component*) malloc(sizeof(Component) * nbComponent);

        result = fread(datas->grid->components, sizeof(Component),nbComponent, file );
        fprintf(stdout, "Electronix has read %d components from %s.elc successfully!\n", nbComponent, filename);

        datas->grid->nbComponents = nbComponent;

        fclose(file);
        return 1;
    }
    fprintf(stderr, "! File Not Found :/ -> Cannot find/open %s.elc\n", filename);
    return 0;
}
