#include "iLevel.h"

int level_init(Datas* datas){
    int nbButton = 16;
    int nbGroup = 1; // menu

    SDL_Rect* rectsGr = (SDL_Rect*) malloc(sizeof(SDL_Rect) * nbGroup);
    SDL_Rect* rectsBt = (SDL_Rect*) malloc(sizeof(SDL_Rect) * nbButton);

    datas->ui->nbBt = nbButton;
    datas->ui->rectBt = rectsBt;
    datas->ui->rectGroup = rectsGr;
    return 0;
}
int level_event(SDL_Event event,SDL_Window* windowP, SDL_Renderer* rendererP,Datas *datas, int *running){
    int width, height;
    int xMouse, yMouse;
    int counterI, counterJ;
    int idBt = -1;
    SDL_Rect currentBt;
    //Refresh buttons' position
    SDL_GetWindowSize(windowP, &width, &height);

    SDL_Rect menu = {width/2-255,
        height/2-105,
        500,
        300};
    SDL_Rect back = {
        width/2-80,
        height/8*7,
        160,
        40
    };
    datas->ui->rectGroup[0] = menu;
    datas->ui->rectBt[0] = back;


    for(counterJ = 0; counterJ < 3; counterJ++){
        for(counterI = 0; counterI < 5; counterI++){
            currentBt = (SDL_Rect) {width/2-250+counterI*100,
                height/2-100+counterJ*100,
                90,
                90};
            datas->ui->rectBt[counterJ * 5 + counterI+1] = currentBt;
        }
    }

    //Mouse on buttons
    SDL_GetMouseState(&xMouse, &yMouse);
    if(event.type == SDL_MOUSEBUTTONDOWN){
        idBt = getIdButtonOn(*datas, xMouse, yMouse);
        switch(idBt){
            case 0:
                level_end(datas);
                menu_init(datas);
                datas->currentIEventsFct = menu_event;
                datas->currentIRenderFct = menu_update;
                break;
        default:
                break;
        }
        if(idBt > 0 && idBt < 16){
            level_end(datas);
            conception_init(datas);
            datas->currentIEventsFct = conception_event;
            datas->currentIRenderFct = conception_update;
        }
    }
    return 0;
}
int level_update(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas){

    int width, height;

    SDL_GetWindowSize(windowP, &width, &height);

    SDL_Rect background = {0,0,width,height};
    SDL_Rect header = {0, height/9, width, height/7};
    SDL_Rect headerT = {
        (width - (height/7 - 20) * datas.surfaces->texts[0]->w/datas.surfaces->texts[0]->h)/2,
        height/9 + 10,
        (height/7 - 20) * datas.surfaces->texts[0]->w/datas.surfaces->texts[0]->h,
        height/7 - 20
    };
    SDL_Rect menu = datas.ui->rectGroup[0];

    SDL_RenderCopy(rendererP, datas.textures->images[7], NULL, &background);
    SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);
    SDL_RenderFillRect(rendererP, &header);
    SDL_SetRenderDrawColor(rendererP, 160, 253, 255, 0);
    SDL_RenderFillRect(rendererP, &menu);

    SDL_RenderCopy(rendererP, datas.textures->texts[0], NULL, &headerT);

    level_update_buttons(rendererP, datas, width, height);

    SDL_RenderPresent(rendererP);
    return 1;
 }

int level_update_buttons(SDL_Renderer* rendererP, Datas datas, int width, int height){
    int counterJ;
    char t[3];
    int idBt;
    int xMouse, yMouse;
    SDL_Rect levelT;
    SDL_Rect back;
    SDL_Rect backT;
    SDL_GetMouseState(&xMouse, &yMouse);
    idBt = getIdButtonOn(datas,xMouse, yMouse);

    if(idBt >= 0){
        datas.ui->rectBt[idBt].x +=2;
        datas.ui->rectBt[idBt].y += 2;
    }
    back = datas.ui->rectBt[0];
    backT = (SDL_Rect){
        back.x + 5,
        back.y + 5,
        back.w - 10,
        back.h -10
    };
    SDL_SetRenderDrawColor(rendererP, 175, 18, 18, 0);
    SDL_RenderFillRect(rendererP, &datas.ui->rectBt[0]);

    SDL_RenderCopy(rendererP, datas.textures->texts[10], NULL, &backT);
    for(counterJ = 0; counterJ < 15; counterJ ++){

            levelT = (SDL_Rect) {
                datas.ui->rectBt[counterJ+1].x +5,
                datas.ui->rectBt[counterJ+1].y +5,
                datas.ui->rectBt[counterJ+1].w -10,
                datas.ui->rectBt[counterJ+1].h -10
            };
            itoa(counterJ+1,t,10);
            t[2] = '\0';
            redrawText(rendererP, &datas, 5, t, 0);
            SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);
            SDL_RenderFillRect(rendererP, &datas.ui->rectBt[counterJ+1]);
            SDL_RenderCopy(rendererP,datas.textures->texts[5],NULL,&levelT);
    }
    return 1;
}


int level_end(Datas *datas){
    free(datas->ui->rectBt);
    free(datas->ui->rectGroup);
    return 1;
}
