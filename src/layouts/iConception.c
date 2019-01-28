#include "iConception.h"

int conception_init(Datas* datas){

    int nbButton = 6;
    int nbGroup = 3;

    //Allocation des éléments UI
    SDL_Rect* rectsBt = (SDL_Rect*) malloc(sizeof(SDL_Rect) * nbButton);
    SDL_Rect* rectsGr = (SDL_Rect*) malloc(sizeof(SDL_Rect) * nbGroup);

    //Si on a aucun composant, on réinitialise la grille
    //Evite la réinitialisation après l'iFileManager
    if(datas->grid->nbComponents == 0){
        gridInit(datas);
    }
    //Affectation des valeurs de l'interface à Datas
    datas->ui->nbBt = nbButton;
    datas->ui->rectBt = rectsBt;
    datas->ui->rectGroup = rectsGr;
    datas->filenameInputTxt[0] = '\0';
    datas->idSel = 0;

    return 0;
}
int conception_event(SDL_Event event,SDL_Window* windowP, SDL_Renderer* rendererP,Datas *datas, int* running){
    int width, height;
    int xMouse, yMouse;
    int marginXHeader;
    float newValueComponent;
    ItemComponent* onComponent;
    int i;
    int idBt = -1;

    //Taille de la fenêtre
    SDL_GetWindowSize(windowP, &width, &height);
    //Marge du header
    marginXHeader = width/2 - 0.2 * width;

    //Rectangle des éléments du header
    SDL_Rect headerB = {marginXHeader, 0, width-marginXHeader*2, height/8};
    SDL_Rect header = {headerB.x+ 5, headerB.y+5, headerB.w -10, headerB.h-10};
    SDL_Rect currentBt = {header.x+10, header.y+10, header.w/5-20,header.h-20};

    //Groupe des paramètres
    SDL_Rect parameters = {marginXHeader,height-height/8,width-marginXHeader*2, height/8};

    //Place les boutons sur le header et dans l'UI
    for(i = 0; i < datas->ui->nbBt-1; i++){
        currentBt.x = header.x+10  +header.w*i/ (datas->ui->nbBt-1) ;
        datas->ui->rectBt[i] = currentBt;
    }
    datas->ui->rectBt[i] = (SDL_Rect) {parameters.x+10, parameters.y+10, 100,40};

    //Place les groupes dans UI
    datas->ui->rectGroup[0] = headerB;
    datas->ui->rectGroup[1] = (SDL_Rect){width-width/8,0, width/8, height};
    datas->ui->rectGroup[2] = parameters;

    //Evenement
    //Action de l'utilisateur sur les boutons
    SDL_GetMouseState(&xMouse, &yMouse);
    if(event.type == SDL_MOUSEBUTTONDOWN){
        idBt = getIdButtonOn(*datas, xMouse, yMouse);
        switch(idBt){
            case 0:
                freeComponents(datas);
                gridInit(datas);
                return 1;
            case 1:
                datas->mode = 0;
                conception_end(datas);
                fileM_init(datas);
                datas->currentIEventsFct = fileM_event;
                datas->currentIRenderFct = fileM_update;
                return 1;
            case 2:
                datas->mode = 1;
                conception_end(datas);
                fileM_init(datas);
                datas->currentIEventsFct = fileM_event;
                datas->currentIRenderFct = fileM_update;
                return 1;
            case 4:
                conception_end(datas);
                freeComponents(datas);
                menu_init(datas);
                datas->currentIEventsFct = menu_event;
                datas->currentIRenderFct = menu_update;
                return 1;
            case 5:
                reverseComponent(datas, datas->grid->selectedComponent);
                return 1;
            default:
                onClickComponent(event.button,datas,(Component){ 0,
                    xMouse/datas->grid->zoomLevel,
                    yMouse/datas->grid->zoomLevel,
                    datas->idSel,
                    0,100,0});
                break;
        }
        onComponent = isEmpty(datas, xMouse/datas->grid->zoomLevel,
                                      yMouse/datas->grid->zoomLevel);
        if(onComponent != NULL){
            datas->grid->selectedComponent = onComponent->component->id;
            sprintf(datas->filenameInputTxt, "%f", onComponent->component->specificData);
            datas->filenameInputTxt[4] = '\0';
        }
        else{
            datas->grid->selectedComponent = -1;
        }
    }

    //Action de l'utilisateur sur le scroll
    if(event.type == SDL_MOUSEWHEEL){
        if(event.wheel.y > 0 && datas->grid->zoomLevel < 100){
            datas->grid->zoomLevel+=3;
        }else if (event.wheel.y < 0 && datas->grid->zoomLevel > 10){
            datas->grid->zoomLevel-=3;
        }
    }
    //Action de l'utilisateur sur les boutons haut et bas
    if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == datas->config.upChoose){
            datas->idSel=(datas->idSel+datas->nbModules-1)%datas->nbModules;
        }else if(event.key.keysym.sym == datas->config.downChoose){
            datas->idSel=(datas->idSel+1)%datas->nbModules;
        }else if(event.key.keysym.sym == datas->config.navUp){
            //datas->grid->focusY-=20;
        }else if(event.key.keysym.sym == datas->config.navDown){
             //datas->grid->focusY+=20;
        }else if(event.key.keysym.sym == datas->config.navLeft){
             //datas->grid->focusX-=20;
        }else if(event.key.keysym.sym == datas->config.navRigth){
             //datas->grid->focusX+=20;
        }
    }
    inputTxtListener(datas, event, 3);
    newValueComponent = atof(datas->filenameInputTxt);
    if(newValueComponent != 0 && datas->grid->selectedComponent < datas->grid->nbComponents){
            setSpecificDataComponent(datas, datas->grid->selectedComponent, newValueComponent);
    }
    return 1;
}
int conception_update(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas){

    int i;
    int width, height;

    SDL_GetWindowSize(windowP,&width, &height);

    //Met en gris le fond d'écran
    SDL_Rect background = {0, 0, width, height};
    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_RenderFillRect(rendererP,&background);

    //Dessine la grille de la page
    SDL_SetRenderDrawColor(rendererP,0,0,0,0);
    for(i = 0; i < height; i+=datas.grid->zoomLevel){
        SDL_RenderDrawLine(rendererP, 0,
                           (i+datas.grid->focusY)%height,
                           width,
                           (i + datas.grid->focusY)%height);
    }
    for(i = 0; i < width; i+=datas.grid->zoomLevel){
        SDL_RenderDrawLine(rendererP, (i+datas.grid->focusX)%width,
                           0,
                           (i+datas.grid->focusX)%width,
                           height);
    }

    //Dessine les composants
    renderComponents(rendererP, datas);

    //Dessine les sous-layouts
    conception_update_modules(rendererP, datas,width, height);
    conception_update_header(rendererP, datas, width,height);
    if(datas.grid->selectedComponent != -1){
        conception_update_parameters(rendererP, datas, width, height);
    }


    //Rend sur l'écran
    SDL_RenderPresent(rendererP);
    return 1;
}
int conception_update_header(SDL_Renderer* rendererP, Datas datas, int width, int height){

    int i;
    int idBt = -1;
    int xMouse, yMouse;
    SDL_Rect headerB = datas.ui->rectGroup[0];
    SDL_Rect header = {headerB.x+5, headerB.y+5, headerB.w -10, headerB.h-10};
    SDL_Rect currentBt;
    SDL_Rect currentIcoBt;

    //Dessine le fond du header
    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_RenderFillRect(rendererP,&headerB);
    SDL_SetRenderDrawColor(rendererP,50,50,50,0);
    SDL_RenderFillRect(rendererP,&header);

    //Dessine les boutons du header
    SDL_GetMouseState(&xMouse, &yMouse);
    idBt = getIdButtonOn(datas,xMouse, yMouse);
    for(i = 0; i < datas.ui->nbBt-1; i++){
        currentBt = datas.ui->rectBt[i];
        //Décale le bouton si la souris est dessus
        if(idBt == i){
            currentBt.x += 2;
            currentBt.y+=2;
        }

        //Dessine le bouton
        SDL_RenderCopy(rendererP,datas.textures->images[5],NULL,
                       &currentBt);
        currentIcoBt.x = currentBt.x+10;
        currentIcoBt.y = currentBt.y+10;
        currentIcoBt.w = currentBt.w-20;
        currentIcoBt.h = currentBt.h-20;
        //Et son icone
        SDL_RenderCopy(rendererP,datas.textures->images[i],NULL,&currentIcoBt);

    }
    return 1;
}
int conception_update_modules(SDL_Renderer* rendererP, Datas datas, int width, int height){

    int i;
    SDL_Rect modulesB = datas.ui->rectGroup[1];
    SDL_Rect modules = {modulesB.x+5, modulesB.y+5, modulesB.w-10, modulesB.h-10};
    SDL_Rect currentMod = {modules.x+5, modules.y+5, modules.w -10, 40};

    //Dessine le fond de ModuleLayout
    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_RenderFillRect(rendererP,&modulesB);
    SDL_SetRenderDrawColor(rendererP,50,50,50,0);
    SDL_RenderFillRect(rendererP,&modules);

    //Dessine les modules
    for(i = 0; i < datas.nbModules; i++){
        currentMod.y = modules.y + 5 +45*i;
        currentMod.h = 40;
        currentMod.w = currentMod.h*datas.surfaces->texts[0]->w / datas.surfaces->texts[0]->h;
        if(currentMod.w > modules.w - 10){
            currentMod.w = modules.w-10;
        }
        showBtModule(rendererP,currentMod,datas, i);
    }
    return 1;

}

int conception_update_parameters(SDL_Renderer* rendererP, Datas datas, int width, int height){

    int idBt = -1;
    int xMouse, yMouse;
    SDL_Rect headerB = datas.ui->rectGroup[2];
    SDL_Rect header = {headerB.x+5, headerB.y+5, headerB.w -10, headerB.h-10};
    SDL_Rect currentBt;
    SDL_Rect currentIcoBt;

    //Dessine le fond du header
    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_RenderFillRect(rendererP,&headerB);
    SDL_SetRenderDrawColor(rendererP,50,50,50,0);
    SDL_RenderFillRect(rendererP,&header);

    //Dessine les boutons du header
    SDL_GetMouseState(&xMouse, &yMouse);
    idBt = getIdButtonOn(datas,xMouse, yMouse);

    currentBt = datas.ui->rectBt[5];
    //Décale le bouton si la souris est dessus
    if(idBt == 5){
        currentBt.x += 2;
        currentBt.y+=2;
    }

    //Dessine le bouton
    SDL_RenderCopy(rendererP,datas.textures->images[5],NULL,
                   &currentBt);
    currentIcoBt = (SDL_Rect) {currentBt.x+10, currentBt.y+10, currentBt.w-20, currentBt.h-20};
    //Et son icone
    SDL_RenderCopy(rendererP,datas.textures->texts[21],NULL,&currentIcoBt);

    currentBt.x += currentBt.w+20;
    currentIcoBt.x += currentBt.w +20;

    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_RenderFillRect(rendererP,&currentBt);
    if(datas.filenameInputTxt[0] != '\0'){
        currentIcoBt.w = strlen(datas.filenameInputTxt) * currentIcoBt.w / 4;
        redrawText(rendererP, &datas, 20, datas.filenameInputTxt, 0);
        SDL_RenderCopy(rendererP,datas.textures->texts[20],NULL,&currentIcoBt);
    }
    return 1;
}

int freeComponents(Datas *datas){
    datas->grid->components = (ItemComponent*) removeAll(datas->grid->components);
    datas->grid->nbComponents = 0;
    return 1;
}
int conception_end(Datas *datas){
    free(datas->ui->rectBt);
    free(datas->ui->rectGroup);
    return 1;
}
