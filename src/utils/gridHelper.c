#include "gridHelper.h"

int* getNeighbourComponent(Datas* datas, Component* component){
    int cId[4];
    int i;
    int u = 0; //bug chelou ; à voir avec M. Sananes
    Component *componentsA[4];

    componentsA[0] = isEmpty(datas, component->posX, component->posY+1);
    componentsA[1] = isEmpty(datas, component->posX, component->posY-1);
    componentsA[2] = isEmpty(datas, component->posX+1, component->posY);
    componentsA[3] = isEmpty(datas, component->posX-1, component->posY);

    for(i = 0; i < 4;i++){
        cId[i] = componentsA[i] == NULL ? -1 : componentsA[i]->id;
        //printf("%d", cId[i]);
    }


    return cId;
}
Component* isEmpty(Datas* datas, int x, int y){

    int i;
    for(i = 0; i < datas->grid->nbComponents; i++){
        if(datas->grid->components[i].posX == x &&
           datas->grid->components[i].posY == y
           && datas->grid->components[i].idModule != -1){
            return datas->grid->components + i;
           }
    }
    return NULL;

}
