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

void getFileList(char result[8][128]){
    DIR *d;
    int nbFile;
    struct dirent *dir;
    char generalName[128];
    int counter =0;
    d = opendir("./saves");
    if(d){
        while((dir = readdir(d)) != NULL){
            if(strlen(dir->d_name) > 4){
                strncpy(generalName,dir->d_name, strlen(dir->d_name) - 4);
                generalName[strlen(dir->d_name)-4] = '\0';
                if(fileExist(generalName) && counter < 8){
                    strcpy(result[counter++], generalName);
                }
            }
        }
        closedir(d);
    }

    for( ; counter < 8; counter++){
        result[counter][0] = '\0';
    }

    return result;
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
