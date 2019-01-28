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
int inputTxtListener(Datas * datas, SDL_Event event, int lenghtMax){
    int keycode;
    char letter;
    short lenght = strlen(datas->filenameInputTxt);
    if(event.type == SDL_KEYDOWN){

        keycode = event.key.keysym.sym;
        if( (124 > keycode && keycode >= 95 ) ||
            (58 > keycode && keycode >= 48) ||
            (32 == keycode)||
            (59 == keycode)){
            if(lenght > lenghtMax) return 0;
            letter = (char)keycode;
            if(letter == ';'){
                letter = '.';
            }
            datas->filenameInputTxt[lenght] = letter;
            datas->filenameInputTxt[lenght+1] = '\0';
        }else if (8 == keycode && lenght> 0){
            datas->filenameInputTxt[lenght-1] = '\0';
        }
    }
    return 1;
}
