#include "iFileManager.h"

int fileM_init(Datas* datas){
    int nbButton = 2;
    int nbGroup = 1;

    SDL_Rect* rectsGr = (SDL_Rect*) malloc(sizeof(SDL_Rect) * nbGroup);
    SDL_Rect* rectsBt = (SDL_Rect*) malloc(sizeof(SDL_Rect) * nbButton);

    datas->ui->nbBt = nbButton;
    datas->ui->rectBt = rectsBt;
    datas->ui->rectGroup = rectsGr;

    return 0;
}
int fileM_event(SDL_Event event,SDL_Window* windowP, SDL_Renderer* rendererP,Datas *datas, int *running){
    int width, height;
    int xMouse, yMouse;
    int counter;
    int idBt = -1;
    SDL_Rect menu;

    //Refresh buttons' position
    SDL_GetWindowSize(windowP, &width, &height);
    menu = (SDL_Rect) {width/2-200, height/2-350, 400, 700};

    datas->ui->rectGroup[0] = menu;

    datas->ui->rectBt[0] = (SDL_Rect){menu.x+10,menu.y+650, menu.w/2 - 20,40};
    datas->ui->rectBt[1] = (SDL_Rect){menu.x+10+menu.w/2,menu.y+650, menu.w/2-20,40};
    //Mouse on buttons
    SDL_GetMouseState(&xMouse, &yMouse);
    if(event.type == SDL_MOUSEBUTTONDOWN){
        idBt = getIdButtonOn(*datas, xMouse, yMouse);
        switch(idBt){
            case 0:
                fileM_end(datas);
                conception_init(datas);
                datas->currentIEventsFct = conception_event;
                datas->currentIRenderFct = conception_update;
                break;
            case 1:

                break;
        }
    }
    return 0;
}
int fileM_update(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas){

    int width, height;

    SDL_Rect menu = datas.ui->rectGroup[0];

    printf("%d,%d,%d,%d\n", menu.x, menu.y, menu.w, menu.h);

    SDL_GetWindowSize(windowP, &width, &height);
    SDL_SetRenderDrawColor(rendererP,50,50,50,0);
    SDL_RenderFillRect(rendererP,&menu);

    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    SDL_RenderFillRect(rendererP,datas.ui->rectBt);
    SDL_RenderFillRect(rendererP,datas.ui->rectBt +1);

    SDL_RenderPresent(rendererP);
 }


int fileM_end(Datas *datas){
    free(datas->ui->rectBt);
    free(datas->ui->rectGroup);
}
