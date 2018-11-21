#include "uiEvent.h"

int getIdButtonOn(Datas datas, int xMouse, int yMouse){

    int i;
    int nbButton = datas.ui->nbBt;

    SDL_Rect currentBt;

    for(i = 0; i < nbButton; i++){

        currentBt = datas.ui->rectBt[i];

        if(currentBt.x < xMouse && xMouse < currentBt.x+currentBt.w
            && currentBt.y < yMouse && yMouse < currentBt.y+currentBt.h){

            return i;
        }
    }
    return -1;

}
