#include "layoutLoader.h"

int initLayouts(SDL_Renderer* rendererP, Datas* datas){

    if(!initTextures(rendererP, datas) |
       initTexsTex(rendererP, datas)){
        return 0;
    }


    return 1;
}
int initTextures(SDL_Renderer* rendererP, Datas* datas){

    int i;
    int nbTex = datas->surfaces->nbImg;
    datas->textures->images = malloc(sizeof(SDL_Texture*) * nbTex);
    if(datas->textures->images == NULL){
        return 0;
    }
    for(i = 0; i < nbTex; i++){
        datas->textures->images[i] = SDL_CreateTextureFromSurface(rendererP,
                                                        datas->surfaces->images[i]);
        if(!datas->textures->images[i]){
            fprintf(stderr,"Texture Creation Error :/ -> %s\n",SDL_GetError());
            return 0;
        }
    }
    return 1;
}
int initTexsTex(SDL_Renderer* rendererP, Datas* datas){

    int i;
    int nbTex = datas->surfaces->nbText;
    datas->textures->texts = malloc(sizeof(SDL_Texture*) * nbTex);
    if(datas->textures->texts == NULL){
        return 0;
    }
    for(i = 0; i < nbTex; i++){
        datas->textures->texts[i] = SDL_CreateTextureFromSurface(rendererP,
                                                                 datas->surfaces->texts[i]);
        if(!datas->textures->texts[i]){
            fprintf(stderr,"Texts Creation Error :/ -> %s\n",SDL_GetError());
            return 0;
        }
    }
    return 1;
}

void redrawText(SDL_Renderer* rendererP, Datas* datas, int ptrText, char * newText){
    SDL_FreeSurface(datas->surfaces->texts[ptrText]);
    SDL_DestroyTexture(datas->textures->texts[ptrText]);

    SDL_Color white = {255,255,255};
    datas->surfaces->texts[ptrText] = TTF_RenderText_Blended(datas->font, newText, white);;
    if(!datas->surfaces->texts[ptrText]){
        fprintf(stderr,"Text Loading Error :/ -> %s\n", TTF_GetError());
        return;
    }
    datas->textures->texts[ptrText] = SDL_CreateTextureFromSurface(rendererP,
                                                                 datas->surfaces->texts[ptrText]);
    if(!datas->textures->texts[ptrText]){
        fprintf(stderr,"Texts Creation Error :/ -> %s\n",SDL_GetError());
        return;
    }

}

int updateRender(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas){
    (*datas.currentIRenderFct)(windowP, rendererP,datas);
}
void updateEvent(SDL_Event event, SDL_Window* windowP, SDL_Renderer * rendererP, Datas * datas, int * running){
    SDL_WaitEvent(&event);
    conception_init(datas);
    conception_event(event, windowP, rendererP,datas);
    switch(event.type)
    {
        case SDL_KEYDOWN:

            //conception_init(datas);
            datas->currentIRenderFct = conception_update;

            break;
        case SDL_QUIT:
            conception_end(*datas);
            *running = 0;
            break;
    }

    if(datas->currentIRenderFct == NULL){
        conception_end(*datas);
        *running = 0;
    }

}
int destroyTextures(Datas datas){
    int i;
    for(i = 0; i < sizeof(datas.textures->images) / sizeof(SDL_Texture*); i++){
        SDL_DestroyTexture(datas.textures->images[i]);
    }
    free(datas.textures->images);
    for(i = 0; i < sizeof(datas.textures->texts) / sizeof(SDL_Texture*); i++){
        SDL_DestroyTexture(datas.textures->texts[i]);
    }
    free(datas.textures->images);
    TTF_CloseFont(datas.font);
}
