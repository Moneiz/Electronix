#include "kernel.h"

void initConf(char * confFilename){

    FILE * file = NULL;

    file = fopen(confFilename,"r");

    if(file != NULL){

        //fscanf(file,"%d %d\n%d %d %d\n",scoreX,scoreY,size,player,mode);

        fclose(file);
    }

}
SDL_Window* initWindow(){
     if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stderr,"Window Initialisation Error :/ -> %s\n",SDL_GetError());
        return NULL;
    }

    SDL_Window* windowP = SDL_CreateWindow("Electronix",SDL_WINDOWPOS_UNDEFINED,
                                                            SDL_WINDOWPOS_UNDEFINED,
                                                            640,
                                                            480,
                                                            SDL_WINDOW_MAXIMIZED);
    SDL_SetWindowResizable(windowP, SDL_TRUE);
    if(windowP == NULL){
        fprintf(stderr,"Window Creation Error :/ -> %s\n",SDL_GetError());
    }

    return windowP;
}
SDL_Renderer* initRenderer(SDL_Window* windowP){

    SDL_Renderer* rendererP = SDL_CreateRenderer(windowP,-1,SDL_RENDERER_ACCELERATED);

    if(rendererP == NULL){
        fprintf(stderr,"Renderer Creation Error :/ -> %s\n", SDL_GetError());
    }
    return rendererP;

}
int initImg()
{
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int codeInit = IMG_Init(flags);
    if((codeInit&flags) != flags){
        fprintf(stderr,"Image Initialisation Error :/ -> %s\n", IMG_GetError());
        return 0;
    }
    return 1;
}
int initTtf(){

    if(TTF_Init() == -1){

        fprintf(stderr, "TTF Initialisation Error :/ -> %s\n", TTF_GetError());
        return 0;

    }
    return 1;
}
int init(SDL_Window** windowP, SDL_Renderer** rendererP){

    *windowP = initWindow();
    if(*windowP != NULL){
        *rendererP = initRenderer(*windowP);
        if(*rendererP == NULL){
            return 0;
        }
    }
    else{
        return 0;
    }
    //Images, text init
    if(!initImg() & !initTtf()){
        return 0;
    }

    return 1;

}
int postInit(SDL_Renderer* rendererP,Datas* datas, Ressources r){

    int i;
    datas->surfaces->images = (SDL_Surface**) malloc(sizeof(SDL_Surface*) * r.sizeListImgFiles);
    for(i = 0; i < r.sizeListImgFiles; i++){
        datas->surfaces->images[i] = IMG_Load((const char*)r.listImgFiles+i);
        if(!datas->surfaces->images[i]){
            fprintf(stderr,"Image Loading Error :/ -> %s\n", IMG_GetError());
            return 0;

        }
    }
    datas->font = TTF_OpenFont(r.font,65);
    if(!( datas->font )){
        fprintf(stderr,"Font Loading Error :/ -> %s\n", IMG_GetError());
        return 0;
    }
    datas->surfaces->texts = (SDL_Surface**) malloc(sizeof(SDL_Surface*) * r.sizeListText);
    SDL_Color white = {255,255,255};
    for(i = 0; i < r.sizeListImgFiles; i++){
        datas->surfaces->texts[i] = TTF_RenderText_Blended(datas->font, (const char*)r.listText+i, white);;
        if(!datas->surfaces->texts[i]){
            fprintf(stderr,"Text Loading Error :/ -> %s\n", IMG_GetError());
            return 0;

        }
    }


    initLayout(rendererP,datas);
    return 1;
}
void freeRessources(Datas datas, Ressources r){

    int i;
    destroyTextures(datas);

    for(i = 0; i < r.sizeListText; i++){
        SDL_FreeSurface(datas.surfaces->texts[i]);
    }
    free(datas.surfaces->texts);

    for(i = 0; i < r.sizeListImgFiles; i++){
        SDL_FreeSurface(datas.surfaces->images[i]);
    }
    free(datas.surfaces->images);
}
void endApp(SDL_Window* windowP, SDL_Renderer* rendererP,Datas datas, Ressources r){

    freeRessources(datas,r);
    TTF_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(rendererP);

    SDL_DestroyWindow(windowP);
    SDL_Quit();
}
int updateApp(SDL_Window* windowP, SDL_Renderer* rendererP, Datas datas){
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        //Appel des layouts
        update(windowP, rendererP, datas);

        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN:
                continuer = 0;
            case SDL_QUIT:
                continuer = 0;
        }
    }
    return 0;

}


