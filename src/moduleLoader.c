#include "moduleLoader.h"

Module* initModules(int nbModule){

    Module *modulesList = (Module*) malloc(sizeof(Module) * nbModule);
    modulesList[0] = (Module) {1, 6, 8};
    modulesList[1] = (Module) {2, 7, 9};
    modulesList[2] = (Module) {3, 8, 10};

    return modulesList;

}
void gridInit(Datas * datas){
    datas->grid->nbComponents = 0;
    datas->grid->components = NULL;
    datas->grid->zoomLevel = 50;
}
void addComponentOnGrid(Datas * datas, Component component){

    int i;
    Component* temp = (Component*) malloc(sizeof(Component) * (datas->grid->nbComponents+1));

    for(i = 0; i < datas->grid->nbComponents; i++){
        temp[i] = datas->grid->components[i];
    }
    temp[datas->grid->nbComponents] = component;
    datas->grid->nbComponents++;
    if(datas->grid->components != NULL){
        free(datas->grid->components);
    }

    datas->grid->components = temp;

}
void freeModules(Module* modulesList){
    free(modulesList);
}

void showBtModule(SDL_Renderer* rendererP,SDL_Rect currentMod, Datas datas, int id){

    SDL_Rect currentModIco = {currentMod.x+5, currentMod.y+5, currentMod.w/4 -10, 30};
    SDL_Rect currentModText = {currentMod.x+20+currentMod.w/4, currentMod.y+15, 3*currentMod.w/4 -30, 10};

    if(id == datas.idSel){
        SDL_SetRenderDrawColor(rendererP, 175, 18, 18, 0);
    }else{
        SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);

    }
    SDL_RenderFillRect(rendererP,&currentMod);
    SDL_RenderCopy(rendererP,datas.textures->images[datas.modulesList[id].idTex],NULL,&currentModIco);
    SDL_RenderCopy(rendererP,datas.textures->texts[datas.modulesList[id].idTextTex],NULL,&currentModText);


}
