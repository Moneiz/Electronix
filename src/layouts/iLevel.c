#include "iLevel.h"
#include "iMenu.h"

int level_init(Datas* datas){
    int nbButton = 5;
    int nbGroup = 4; // menu

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
    int counter;
    int idBt = -1;
    int buttonX, buttonY, buttonW, buttonH;

    //Refresh buttons' position
    SDL_GetWindowSize(windowP, &width, &height);

    buttonX = width/2 - width/8 + width/200;
    buttonY = height/3 + height/100;
    buttonW = (width/4 - 2 * width/200);
    buttonH = (height/2 - (datas->ui->nbBt + 1) * height/100)/datas->ui->nbBt;

    SDL_Rect menu = {width/4, height/3, width/2 - width/200, height/2 - height/200};
    // SDL_Rect Line1 = ////;
    // SDL_Rect Line2 = ////;
    // SDL_Rect Line3 = ////;
    SDL_Rect currentBt;
    for(counter = 0; counter < datas->ui->nbBt; counter++){
        SDL_Rect currentBt = {buttonX, buttonY + counter * (height/100 + buttonH), buttonW, buttonH};
        datas->ui->rectBt[counter] = currentBt;
    }

    // datas->ui->rectGroup[0] = menu;
    // datas->ui->rectGroup[1] = Line1;
    // datas->ui->rectGroup[1] = Line2;
    // datas->ui->rectGroup[1] = Line3;
    //EVENT MANAGER

    //Mouse on buttons
    SDL_GetMouseState(&xMouse, &yMouse);
    if(event.type == SDL_MOUSEBUTTONDOWN){
        idBt = getIdButtonOn(*datas, xMouse, yMouse);
        switch(idBt){
            case 0:
                // datas->currentIRenderFct = ;
                break;
            case 1:
                // datas->currentIRenderFct = ;
                break;
            case 2:
                // datas->currentIRenderFct = ;
                break;
            case 3:
                // endApp;
                break;
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
    SDL_Rect menu = {width/4, height/3, width/2 - width/200, height/2 - height/200};
    SDL_Rect back = {
        width/3,
        2*height/3 + height/5,
        width/3,
        height/10
    };
    SDL_Rect backT = {
        (width - (height/10 - 20) *datas.surfaces->texts[3]->w/datas.surfaces->texts[3]->h)/2,
        2*height/3 + height/5 + 10,
        (height/10 - 20) *datas.surfaces->texts[3]->w/datas.surfaces->texts[3]->h,
        height/10 - 20
    };

    SDL_RenderCopy(rendererP, datas.textures->images[7], NULL, &background);
    SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);
    SDL_RenderFillRect(rendererP, &header);
    SDL_SetRenderDrawColor(rendererP, 160, 253, 255, 0);
    SDL_RenderFillRect(rendererP, &menu);
    SDL_SetRenderDrawColor(rendererP, 175, 18, 18, 0);
    SDL_RenderFillRect(rendererP, &back);
    SDL_RenderCopy(rendererP, datas.textures->texts[0], NULL, &headerT);
    SDL_RenderCopy(rendererP, datas.textures->texts[3], NULL, &backT);

    level_update_buttons(rendererP, datas, width, height);

    SDL_RenderPresent(rendererP);
 }

int level_update_buttons(SDL_Renderer* rendererP, Datas datas, int width, int height){
   int counterI, counterJ, buttonX, buttonY, buttonW, buttonH, columns, lines;;
    SDL_Rect buttons[3][5];

    columns = 5;
    lines = 3;
    buttonX = width/4 + width/200;
    buttonY = height/3 + height/100;
    buttonW = (width/2 - (columns + 1) * width/200)/columns;
    buttonH = (height/2 - (lines + 1) * height/100)/lines;

    for(counterI = 0; counterI < 3; counterI ++){
        for(counterJ = 0; counterJ < 5; counterJ ++){
            buttons[counterI][counterJ].x = buttonX + counterJ * (height/100 + buttonW);
            buttons[counterI][counterJ].y = buttonY + counterI * (width/200 + buttonH) ;
            buttons[counterI][counterJ].w = buttonW;
            buttons[counterI][counterJ].h = buttonH;
            SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);
            SDL_RenderFillRect(rendererP, &buttons[counterI][counterJ]);
        }
    }
}

// int menu_update_buttons(SDL_Renderer* rendererP, Datas datas, int width, int height){

//     int i;
//     int idBt = -1;
//     int xMouse, yMouse;
//     int TxtW, TxtH;

//     SDL_Rect menu = datas.ui->rectGroup[0];
//     SDL_Rect currentBt;
//     SDL_Rect currentTxtBt;

//     SDL_SetRenderDrawColor(rendererP,160, 253, 255, 0);
//     SDL_RenderFillRect(rendererP,&menu);

//     SDL_GetMouseState(&xMouse, &yMouse);
//     idBt = getIdButtonOn(datas,xMouse, yMouse);


//     for(i = 0; i < datas.ui->nbBt; i++){
//         currentBt = datas.ui->rectBt[i];
//             TxtH = datas.surfaces->texts[i + 1]->h;
//             TxtW = datas.surfaces->texts[i + 1]->w;
//         if(idBt == i){
//             currentBt.x += 2;
//             currentBt.y+=2;
//         }
//         if(i == 2){
//             SDL_SetRenderDrawColor(rendererP, 175, 18, 18, 0);
//         }else{
//             SDL_SetRenderDrawColor(rendererP, 21, 51, 54, 0);
//         }
//         SDL_RenderFillRect(rendererP, &currentBt);
//         currentTxtBt.y = currentBt.y + 30;
//         currentTxtBt.h = currentBt.h - 60;
//         currentTxtBt.w = currentTxtBt.h * TxtW/TxtH;
//         currentTxtBt.x = currentBt.x + ( currentBt.w - currentTxtBt.w)/2;
//         SDL_RenderCopy(rendererP,datas.textures->texts[1 + i],NULL,&currentTxtBt);
//     }
// }

int level_end(Datas datas){
    free(datas.ui->rectBt);
    free(datas.ui->rectGroup);
}
