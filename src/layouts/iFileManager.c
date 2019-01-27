#include "iFileManager.h"

int fileM_init(Datas* datas){
    int nbButton = 2;
    int nbGroup = 2;

    SDL_Rect* rectsGr = (SDL_Rect*) malloc(sizeof(SDL_Rect) * nbGroup);
    SDL_Rect* rectsBt = (SDL_Rect*) malloc(sizeof(SDL_Rect) * nbButton);

    datas->ui->nbBt = nbButton;
    datas->ui->rectBt = rectsBt;
    datas->ui->rectGroup = rectsGr;

    getFileList(datas, datas->fileList);

    //fichier pointé par défaut
    if(datas->filePtr == -1)
        datas->filePtr = 0;

    //fond d'écran assombri initialisé
    datas->ui->rectGroup[1] = (SDL_Rect) {-1,-1,-1,-1};
    strcpy(datas->filenameInputTxt,datas->fileList[datas->filePtr]);
    return 0;
}
int fileM_event(SDL_Event event,SDL_Window* windowP, SDL_Renderer* rendererP,Datas *datas, int *running){
    int width, height;
    int xMouse, yMouse;
    int counter;
    int idBt = -1;
    int i;
    SDL_Rect menu;

    //Refresh buttons' position
    SDL_GetWindowSize(windowP, &width, &height);
    menu = (SDL_Rect) {width/2-200, height/2-350, 300, 700};

    datas->ui->rectGroup[0] = menu;
    if(datas->ui->rectGroup[1].w == -1)
        datas->ui->rectGroup[1] = (SDL_Rect) {0,0,width,height};
    else if (datas->ui->rectGroup[1].w == width)
        datas->ui->rectGroup[1] = (SDL_Rect) {0,0,1,1};

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

                if(datas->mode == 0 && loadCircuit(datas->fileList[datas->filePtr],datas)
                    || datas->mode == 1 && saveCircuit(datas->filenameInputTxt, *datas))
                {
                    fileM_end(datas);
                    conception_init(datas);
                    datas->currentIEventsFct = conception_event;
                    datas->currentIRenderFct = conception_update;
                }
                break;
        }
    }
    if(event.type == SDL_KEYDOWN){
        for(i = 0; datas->fileList[i][0] != '\0';i++){}
        if(event.key.keysym.sym == datas->config.upChoose){
            datas->filePtr=(datas->filePtr+i-1)%i;
            strcpy(datas->filenameInputTxt , datas->fileList[datas->filePtr]);
        }else if (event.key.keysym.sym == datas->config.downChoose){
            datas->filePtr=(datas->filePtr+1)%i;
            strcpy(datas->filenameInputTxt , datas->fileList[datas->filePtr]);
        }
    }
    inputTxtListener(datas, event,25);
    return 0;
}
int fileM_update(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas){

    int width, height;
    int i ;

    //Declaration des éléments
    SDL_Rect background ;
    SDL_Rect menu = datas.ui->rectGroup[0];
    SDL_Rect listBackgroud, inputTxt;
    SDL_Rect button;
    SDL_Rect buttonT;
    SDL_Rect curButtonFileName;
    SDL_Rect curFileName;

    if(datas.ui->rectGroup[1].w == -1) return;

    //Taille de la fenetre
    SDL_GetWindowSize(windowP, &width, &height);

    //Assombrissement du layout de fond
    SDL_SetRenderDrawBlendMode(rendererP, SDL_BLENDMODE_BLEND);
    {
        SDL_SetRenderDrawColor(rendererP,0,0,0,200);
        SDL_RenderFillRect(rendererP,datas.ui->rectGroup + 1);
    }
    SDL_SetRenderDrawBlendMode(rendererP, SDL_BLENDMODE_NONE);

    //Dessin de l'interface
    SDL_SetRenderDrawColor(rendererP,50,50,50,0);
    SDL_RenderFillRect(rendererP,&menu);

    SDL_SetRenderDrawColor(rendererP,100,100,100,0);
    if(datas.mode == 0){
        listBackgroud = (SDL_Rect) {menu.x+10, menu.y+10, menu.w -20, menu.h -70};
        inputTxt = (SDL_Rect) {0, 0, 1,1};
    }else{
        listBackgroud = (SDL_Rect) {menu.x+10, menu.y+10, menu.w -20, menu.h -130};
        inputTxt = (SDL_Rect) {menu.x+10, menu.y+menu.h-110, menu.w-20, 50};
    }

    SDL_RenderFillRect(rendererP,&listBackgroud);
    SDL_RenderFillRect(rendererP,&inputTxt);


    //Dessin des boutons
    for(i = 0; i < 2;i++){
        button = datas.ui->rectBt[i];
        buttonT = (SDL_Rect) {button.x+10, button.y +5, button.w -20, button.h -10};
        SDL_RenderFillRect(rendererP,&button);
        if(i == 1 && datas.mode == 1) i = 2;
        SDL_RenderCopy(rendererP, datas.textures->texts[10+i], NULL, &buttonT);
    }

    //Dessin des filenames
    for(i = 0; i < 8;i++){
        if(datas.fileList[i][0] == 0) break;
        redrawText(rendererP, &datas, 13, datas.fileList[i],0);

        curFileName = (SDL_Rect) {listBackgroud.x+10, listBackgroud.y+12 + (i*25),
            strlen(datas.fileList[i])*10, 15};
        curButtonFileName = (SDL_Rect) {listBackgroud.x+10, listBackgroud.y+10 + (i*25),
            listBackgroud.w-20, 20};
        if(i == datas.filePtr)
            SDL_SetRenderDrawColor(rendererP,100,0,0,0);
        else
            SDL_SetRenderDrawColor(rendererP,100,100,100,0);


        SDL_RenderFillRect(rendererP,&curButtonFileName);
        SDL_RenderCopy(rendererP, datas.textures->texts[13], NULL, &curFileName);
    }
    if(strlen(datas.filenameInputTxt)){
        redrawText(rendererP, &datas, 13, datas.filenameInputTxt,0);
        curFileName = (SDL_Rect) {inputTxt.x+10, inputTxt.y+15, strlen(datas.filenameInputTxt)*10, inputTxt.h-30};
        SDL_RenderCopy(rendererP, datas.textures->texts[13], NULL, &curFileName);
    }
    //Rendu
    SDL_RenderPresent(rendererP);
 }


int fileM_end(Datas *datas){
    free(datas->ui->rectBt);
    free(datas->ui->rectGroup);
}
