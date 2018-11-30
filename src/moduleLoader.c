#include "moduleLoader.h"

Module* initModules(int nbModule){

    Module *modulesList = (Module*) malloc(sizeof(Module) * nbModule);
    modulesList[0] = (Module) {1, 6, 8, generator_drawComponent};
    modulesList[1] = (Module) {2, 7, 9, wire_drawComponent};
    modulesList[2] = (Module) {3, 8, 10, resistor_drawComponent};
    modulesList[3] = (Module) {4, 9, 12, NULL};

    return modulesList;

}
void gridInit(Datas * datas){
    datas->grid->nbComponents = 0;
    datas->grid->components = NULL;
    datas->grid->zoomLevel = 50;
}
void onClickComponent(SDL_MouseButtonEvent mEvent,Datas* datas, Component component){
    if(mEvent.button == SDL_BUTTON_LEFT){
        if(isEmpty(datas, component.posX, component.posY) == NULL){
            addComponentOnGrid(datas, component);
        }
    }
    else if(mEvent.button == SDL_BUTTON_RIGHT){
        if(isEmpty(datas, component.posX, component.posY) != NULL){
            removeComponentOnGrid(datas, component);
        }
    }
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
    updateStateComponents(&datas->grid->components[i],datas,1);

}
void removeComponentOnGrid(Datas * datas, Component component){

    int i;
    int idToRemove = 0;

    for(i = 0; i < datas->grid->nbComponents; i++){
        if(datas->grid->components[i].posX == component.posX &&
           datas->grid->components[i].posY == component.posY){
                idToRemove = i;
           }
    }

    datas->grid->components[idToRemove].idModule = -1;
    updateStateComponents(&datas->grid->components[idToRemove],datas,1);

    Component* temp = (Component*) malloc(sizeof(Component) * (datas->grid->nbComponents-1));

    for(i = 0; i < idToRemove; i++){
        temp[i] = datas->grid->components[i];
    }
    for(i = idToRemove; i < datas->grid->nbComponents-1;i++){
        temp[i] = datas->grid->components[i+1];
    }

    datas->grid->nbComponents--;
    if(datas->grid->components != NULL){
        free(datas->grid->components);
    }
    datas->grid->components = temp;

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
void freeModules(Module* modulesList){
    free(modulesList);
}

void updateStateComponents(Component* component, Datas* datas, int recursive){

    Component* topC, *bottomC, *rightC, *leftC;
    int t,b,r,l;
    int nbLink;

    topC = isEmpty(datas, component->posX, component->posY+1);
    bottomC = isEmpty(datas, component->posX, component->posY-1);
    rightC = isEmpty(datas, component->posX+1, component->posY);
    leftC = isEmpty(datas, component->posX-1, component->posY);

    t = topC != NULL;
    b = bottomC != NULL;
    r = rightC != NULL;
    l = leftC != NULL;

    nbLink = t + b + r + l;

    if(nbLink == 2){
        if(r && l)
            component->stateModule = 0;
        else if(t && b)
            component->stateModule = 1;
        else if(b && r)
            component->stateModule = 2;
        else if(t && r)
            component->stateModule = 3;
        else if(t && l)
            component->stateModule = 4;
        else if(b && l)
            component->stateModule = 5;
    }else if(nbLink == 3){
        if(l && b && r)
            component->stateModule =6;
        else if(b && r && t)
            component->stateModule =7;
        else if(r && t && l)
            component->stateModule =8;
        else if(t && l && b)
            component->stateModule =9;
    }
    else if(nbLink == 4){
        component->stateModule = 10;
    }
    if(recursive){
        if(t) updateStateComponents(topC,datas,0);
        if(b) updateStateComponents(bottomC,datas,0);
        if(r) updateStateComponents(rightC,datas,0);
        if(l) updateStateComponents(leftC,datas,0);
    }

}

void renderComponents(SDL_Renderer* rendererP, Datas datas){

    int i;
    int currentIdTexturesComponent;
    Component currentComponent;
    SDL_Rect currentRect = {0,
        0,
        datas.grid->zoomLevel,
        datas.grid->zoomLevel};

    for(i = 0; i < datas.grid->nbComponents; i++){
        currentRect.x = datas.grid->components[i].posX*datas.grid->zoomLevel;
        currentRect.y = datas.grid->components[i].posY*datas.grid->zoomLevel;
        currentComponent = datas.grid->components[i];

        //Obtient l'id de la texture à partir de l'id du composant
        currentIdTexturesComponent = datas.modulesList[currentComponent.idModule].idTex;

        if(datas.modulesList[currentComponent.idModule].ptrFctRender != NULL){
           (datas.modulesList[currentComponent.idModule].ptrFctRender)
           (currentRect, currentComponent, currentIdTexturesComponent,
                              rendererP, datas.textures->images);
        }
        else{
            SDL_RenderCopy(rendererP,
                     datas.textures->images[currentIdTexturesComponent],
                     NULL,
                     &currentRect);
        }

    }


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
