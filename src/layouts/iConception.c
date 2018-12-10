#include "iConception.h"

int conception_init(Datas* datas){

    int nbButton = 5;
    int nbGroup = 2;


    SDL_Rect* rectsBt = (SDL_Rect*) malloc(sizeof(SDL_Rect) * nbButton);
    SDL_Rect* rectsGr = (SDL_Rect*) malloc(sizeof(SDL_Rect) * nbGroup);

    gridInit(datas);

    datas->ui->nbBt = nbButton;
    datas->ui->rectBt = rectsBt;
    datas->ui->rectGroup = rectsGr;

    datas->idSel = 0;

    return 0;
}
int conception_event(SDL_Event event,SDL_Window* windowP, SDL_Renderer* rendererP,Datas *datas, int* running){
    int width, height;
    int xMouse, yMouse;
    int marginXHeader;
    int i;
    int idBt = -1;

    //Refresh buttons' position
    SDL_GetWindowSize(windowP, &width, &height);

    marginXHeader = width/2 - 0.2 * width;

    SDL_Rect headerB = {marginXHeader, 0, width-marginXHeader*2, height/8};
    SDL_Rect header = {headerB.x+ 5, headerB.y+5, headerB.w -10, headerB.h-10};
    SDL_Rect currentBt = {header.x+10, header.y+10, header.w/5-20,header.h-20};
    for(i = 0; i < datas->ui->nbBt; i++){
        currentBt.x = header.x+10  +header.w*i/ datas->ui->nbBt ;
        datas->ui->rectBt[i] = currentBt;
    }
    datas->ui->rectGroup[0] = headerB;
    datas->ui->rectGroup[1] = (SDL_Rect){width-width/8,0, width/8, height};

    //EVENT MANAGER

    //Mouse on buttons
    SDL_GetMouseState(&xMouse, &yMouse);
    if(event.type == SDL_MOUSEBUTTONDOWN){
        idBt = getIdButtonOn(*datas, xMouse, yMouse);
        switch(idBt){
            case 0:
                free(datas->grid->components);
                gridInit(datas);
                break;
            case 1:
                datas->realTimeEnable = 1;
                break;
            case 2:
                datas->realTimeEnable = 0;
                break;
            case 4:
                conception_end(*datas);
                menu_init(datas);
                datas->currentIEventsFct = menu_event;
                datas->currentIRenderFct = menu_update;
                break;
            default:
                onClickComponent(event.button,datas,(Component){ 0,
                    xMouse/datas->grid->zoomLevel,
                    yMouse/datas->grid->zoomLevel,
                    datas->idSel,
                    0,0,0,0});
                break;
        }
    }
    if(event.type == SDL_MOUSEWHEEL){
        if(event.wheel.y > 0 && datas->grid->zoomLevel < 100){
            datas->grid->zoomLevel+=3;
        }else if (event.wheel.y < 0 && datas->grid->zoomLevel > 10){
            datas->grid->zoomLevel-=3;
        }
    }
    if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_UP){
            datas->idSel=(datas->idSel+datas->nbModules-1)%datas->nbModules;
        }else if(event.key.keysym.sym == SDLK_DOWN){
            datas->idSel=(datas->idSel+1)%datas->nbModules;
        }
    }
    return 0;
}
int conception_update(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas){

    int i;
    int width, height;

    SDL_GetWindowSize(windowP,&width, &height);

    SDL_Rect background = {0, 0, width, height};
    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_RenderFillRect(rendererP,&background);

    //Dessine la grille de la page
    SDL_SetRenderDrawColor(rendererP,0,0,0,0);
    for(i = 0; i < height; i+=datas.grid->zoomLevel){
        SDL_RenderDrawLine(rendererP, 0, i, width, i);
    }
    for(i = 0; i < width; i+=datas.grid->zoomLevel){
        SDL_RenderDrawLine(rendererP, i, 0, i, height);
    }

    renderComponents(rendererP, datas);

    //Header
    conception_update_header(rendererP, datas, width,height);
    conception_update_modules(rendererP, datas,width, height);

    SDL_RenderPresent(rendererP);
}
int conception_update_header(SDL_Renderer* rendererP, Datas datas, int width, int height){

    //elements between marginX 0 width-marginX*2 height/8 !

    int i;
    int idBt = -1;
    int xMouse, yMouse;
    int marginXHeader = width/2 - 0.2 * width;
    SDL_Rect headerB = datas.ui->rectGroup[0];
    SDL_Rect header = {headerB.x+5, headerB.y+5, headerB.w -10, headerB.h-10};
    SDL_Rect currentBt;
    SDL_Rect currentIcoBt;

    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_RenderFillRect(rendererP,&headerB);

    SDL_SetRenderDrawColor(rendererP,50,50,50,0);
    SDL_RenderFillRect(rendererP,&header);

    SDL_GetMouseState(&xMouse, &yMouse);
    idBt = getIdButtonOn(datas,xMouse, yMouse);

    for(i = 0; i < datas.ui->nbBt; i++){
        currentBt = datas.ui->rectBt[i];

        if(idBt == i){
            currentBt.x += 2;
            currentBt.y+=2;
        }


        SDL_RenderCopy(rendererP,datas.textures->images[5],NULL,
                       &currentBt);
        currentIcoBt.x = currentBt.x+10;
        currentIcoBt.y = currentBt.y+10;
        currentIcoBt.w = currentBt.w-20;
        currentIcoBt.h = currentBt.h-20;
        SDL_RenderCopy(rendererP,datas.textures->images[i],NULL,&currentIcoBt);

    }



}
int conception_update_modules(SDL_Renderer* rendererP, Datas datas, int width, int height){

    //elements between width-width/8 0 width/8 height !

    int i;
    SDL_Rect modulesB = datas.ui->rectGroup[1];
    SDL_Rect modules = {modulesB.x+5, modulesB.y+5, modulesB.w-10, modulesB.h-10};
    SDL_Rect currentMod = {modules.x+5, modules.y+5, modules.w -10, 40};
    SDL_Rect currentModIco = {currentMod.x+5, currentMod.y+5, currentMod.w/3 -10, 30};
    SDL_Rect currentModText = {currentMod.x+10+currentMod.w/3, currentMod.y+5, 2*currentMod.w/3 -10, 20};

    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_RenderFillRect(rendererP,&modulesB);
    SDL_SetRenderDrawColor(rendererP,50,50,50,0);
    SDL_RenderFillRect(rendererP,&modules);

    for(i = 0; i < datas.nbModules; i++){
        currentMod.y = modules.y + 5 +45*i;
        currentMod.h = 40;
        currentMod.w = currentMod.h*datas.surfaces->texts[0]->w / datas.surfaces->texts[0]->h;
        if(currentMod.w > modules.w - 10){
            currentMod.w = modules.w-10;
        }
        showBtModule(rendererP,currentMod,datas, i);
    }

}
int conception_end(Datas datas){
    free(datas.ui->rectBt);
    free(datas.ui->rectGroup);
    datas.grid->nbComponents = 0;
    free(datas.grid->components);
}
