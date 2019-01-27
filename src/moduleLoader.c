#include "moduleLoader.h"

Module* initModules(int nbModule){
    //On crée un tableau qui contiendra les modules
    //et on le remplit par les modules chargés
    Module *modulesList = (Module*) malloc(sizeof(Module) * nbModule);
    fillModuleList(modulesList);

    return modulesList;

}
void gridInit(Datas * datas){
    //La (ré)-initialisation de la grille se traduit par :
    //-un nombre de composant de 0
    //-tableau components pointant sur NULL
    //-un niveau de zoom par défaut
    freeComponents(datas);
    datas->grid->zoomLevel = 50;
    datas->grid->focusX = 0.5;
    datas->grid->focusY = 0.5;
    datas->grid->selectedComponent = -1;
}
void onClickComponent(SDL_MouseButtonEvent mEvent,Datas* datas, Component component){
    //Le clique gauche sur l'interface de conception
    //va vérifier qu'aucun module existe à l'emplacement donné
    //et ajoutera ensuite un élément à l'emplacement du curseur
    ItemComponent item = (ItemComponent) {&component, NULL};
    if(mEvent.button == SDL_BUTTON_LEFT){
        if(isEmpty(datas, component.posX, component.posY) == NULL
           && canPlaceHere(datas, &item,1)){
            addComponentOnGrid(datas, component);
        }
    }
    //Le clique droit sur l'interface de conception
    //va vérifier que le curseur est sur un composant
    //et le détruira
    else if(mEvent.button == SDL_BUTTON_RIGHT){
        if(isEmpty(datas, component.posX, component.posY) != NULL){
            removeComponentOnGrid(datas, component);
        }
    }
}
void addComponentOnGrid(Datas * datas, Component component){
    datas->grid->nbComponents++;
    component.id = datas->grid->nbComponents -1 ;
    addItem(&datas->grid->components, component);
    updateStateComponents(datas->grid->components,datas, 1);
}
void removeComponentOnGrid(Datas * datas, Component component){
    ItemComponent *item = getComponentByPos(datas->grid->components, component.posX, component.posY);
    item->component->id = -1;
    updateStateComponents(item,datas,1);
    datas->grid->components = removeItemAt(datas->grid->components, item->component->id);

}
int canPlaceHere(Datas* datas,ItemComponent *component, int recursive){
    ItemComponent* topC, *bottomC, *rightC, *leftC;
    int nbLink;
    int nb = 0;

    //On récupère le composant (lié à l'existance ou non) des composants voisins
    topC = isEmpty(datas, component->component->posX, component->component->posY+1);
    bottomC = isEmpty(datas, component->component->posX, component->component->posY-1);
    rightC = isEmpty(datas, component->component->posX+1, component->component->posY);
    leftC = isEmpty(datas, component->component->posX-1, component->component->posY);

    //On additionne les composants qui existe
    nbLink = (topC != NULL) + (bottomC != NULL) + (rightC != NULL) + (leftC != NULL);

    //Si le nombre de lien exigé par le composant est inférieur au nombre de voisin
    //et si on est dans un cas récursif:
    if(datas->modulesList[component->component->idModule].nbLink >= nbLink && recursive){
        //On ajoute 1 si le composant est nulle ou si le voisin autorise une nouvelle liaison
        nb += topC != NULL ? canPlaceHere(datas, topC,0) : 1;
        nb += bottomC != NULL ? canPlaceHere(datas, bottomC,0) : 1;
        nb += leftC != NULL ? canPlaceHere(datas, leftC,0) : 1;
        nb += rightC != NULL ? canPlaceHere(datas, rightC,0) : 1;
        return nb == 4;

    }
    //Si on est pas dans un récursif, on renvoie simplement 1
    if(datas->modulesList[component->component->idModule].nbLink > nbLink && !recursive){
        return 1;
    }
    //Dans tous les autres, on renvoie 0
    return 0;
}

void freeModules(Module* modulesList){
    //On désalloue les modules chargés
    free(modulesList);
}

void updateStateComponents(ItemComponent* component, Datas* datas, int recursive){

    ItemComponent* topC, *bottomC, *rightC, *leftC;
    int t,b,r,l;
    int nbLink;

    //On récupère les différents voisins de composant
    topC = isEmpty(datas, component->component->posX, component->component->posY+1);
    bottomC = isEmpty(datas, component->component->posX, component->component->posY-1);
    rightC = isEmpty(datas, component->component->posX+1, component->component->posY);
    leftC = isEmpty(datas, component->component->posX-1, component->component->posY);

    //On récupère la valeur de leur existance ou non
    t = topC != NULL;
    b = bottomC != NULL;
    r = rightC != NULL;
    l = leftC != NULL;

    //On additionne le tout (pour connaitre le nombre de voisin)
    nbLink = t + b + r + l;

    //On traduit la position des voisins en un état du composant
    if(nbLink == 2){
        if(r && l)
            component->component->stateModule = 0;
        else if(t && b)
            component->component->stateModule = 1;
        else if(b && r)
            component->component->stateModule = 2;
        else if(t && r)
            component->component->stateModule = 3;
        else if(t && l)
            component->component->stateModule = 4;
        else if(b && l)
            component->component->stateModule = 5;
    }else if(nbLink == 3){
        if(l && b && r)
            component->component->stateModule =6;
        else if(b && r && t)
            component->component->stateModule =7;
        else if(r && t && l)
            component->component->stateModule =8;
        else if(t && l && b)
            component->component->stateModule =9;
    }
    else if(nbLink == 4){
        component->component->stateModule = 10;
    }
    //Dans le cas récursif, on applique la mise à jour au voisin également
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
    ItemComponent* currentComponent = datas.grid->components;
    //On crée le rectangle qui dessinera le composant
    SDL_Rect currentRect = {0,
        0,
        datas.grid->zoomLevel,
        datas.grid->zoomLevel};
    //On itère tous les composans de la grille
    for(i = 0; i < datas.grid->nbComponents && currentComponent != NULL; i++){
        //On récupère le composant itéré
        if(currentComponent == NULL) continue;


        //On définit la position du rectangle par la position du composant
        currentRect.x = currentComponent->component->posX*datas.grid->zoomLevel;
        currentRect.y = currentComponent->component->posY*datas.grid->zoomLevel;

        //Obtient l'id de la texture à partir de l'id du composant
        currentIdTexturesComponent = datas.modulesList[currentComponent->component->idModule].idTex;

        //Si le pointeur de fonction dessinant le composant n'est pas nulle,
        //on l'appelle pour déssiner à sa manière le composant
        if(datas.modulesList[currentComponent->component->idModule].ptrFctRender != NULL){
           (datas.modulesList[currentComponent->component->idModule].ptrFctRender)
           (currentRect, *currentComponent->component, currentIdTexturesComponent,
                              rendererP, datas);
        }
        else{
            //Sinon, on le dessine en "brute"
            SDL_RenderCopy(rendererP,
                     datas.textures->images[currentIdTexturesComponent],
                     NULL,
                     &currentRect);
        }
        currentComponent =currentComponent->next;

    }


}

void showBtModule(SDL_Renderer* rendererP,SDL_Rect currentMod, Datas datas, int id){

    SDL_Rect currentModIco = {currentMod.x+5, currentMod.y+5, currentMod.w/4 -10, 30};
    SDL_Rect currentModText = {currentMod.x+20+currentMod.w/4, currentMod.y+15, 3*currentMod.w/4 -30, 10};

    //Si l'id du composant pointé est celle de l'id, on le colorie en rouge
    if(id == datas.idSel){
        SDL_SetRenderDrawColor(rendererP, 175, 18, 18, 0);
    }//Sinon, en gris moyen
    else{
        SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);

    }
    //On déssine le bouton
    SDL_RenderFillRect(rendererP,&currentMod);
    SDL_RenderCopy(rendererP,datas.textures->images[datas.modulesList[id].idTex],NULL,&currentModIco);
    SDL_RenderCopy(rendererP,datas.textures->texts[datas.modulesList[id].idTextTex],NULL,&currentModText);


}
