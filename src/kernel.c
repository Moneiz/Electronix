#include "kernel.h"

SDL_Window* initWindow(){
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 )
    {
        fprintf(stderr,"Window Initialisation Error :/ -> %s\n",SDL_GetError());
        return NULL;
    }

    SDL_Window* windowP = SDL_CreateWindow("",SDL_WINDOWPOS_UNDEFINED,
                                                            SDL_WINDOWPOS_UNDEFINED,
                                                            640,
                                                            480,
                                                            SDL_WINDOW_MAXIMIZED);
    //SDL_SetWindowResizable(windowP, SDL_TRUE);
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

int initAudio(Datas *datas){
    SDL_AudioSpec outAudio = datas->outAudio;
    outAudio.freq = 22050;
    outAudio.format = AUDIO_S16;
    outAudio.channels = 2;
    outAudio.samples = 1024;
 //   outAudio.callback = fill_audio;
    outAudio.userdata = NULL;

    if(SDL_OpenAudio(&outAudio, NULL) == 0){
        fprintf(stderr, "Audio Initialization Error :/ -> %s\n", SDL_GetError());
        return 0;
    }
}

int init(SDL_Window** windowP, SDL_Renderer** rendererP, Ressources r){

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

    if(!r.config.maximized){
        SDL_SetWindowSize(*windowP, r.config.width, r.config.height);
    }
    if(r.config.fullscreen)
        SDL_SetWindowFullscreen(*windowP, SDL_WINDOW_FULLSCREEN_DESKTOP);

    return 1;

}
int postInit(SDL_Renderer* rendererP,Datas* datas, Ressources r){

    int i;
    datas->surfaces->images = (SDL_Surface**) malloc(sizeof(SDL_Surface*) * r.sizeListImgFiles);
    if(datas->surfaces->images == NULL){
        return errMemoryUnalloc(sizeof(SDL_Surface*) * r.sizeListImgFiles);
    }
    for(i = 0; i < r.sizeListImgFiles; i++){
        datas->surfaces->images[i] = IMG_Load(r.listImgFiles+i);
        if(!datas->surfaces->images[i]){
            fprintf(stderr,"Image Loading Error :/ -> %s\n", IMG_GetError());
            return 0;

        }
        fprintf(stderr,"Image Loaded Successful : %s\n", r.listImgFiles+i);
    }
    datas->surfaces->nbImg = r.sizeListImgFiles;


    datas->font = TTF_OpenFont(r.font,65);
    if(!( datas->font )){
        fprintf(stderr,"Font Loading Error :/ -> %s\n", IMG_GetError());
        return 0;
    }


    datas->surfaces->texts = (SDL_Surface**) malloc(sizeof(SDL_Surface*) * r.sizeListText);
    if(datas->surfaces->texts == NULL){
        return errMemoryUnalloc(sizeof(SDL_Surface*) * r.sizeListText);
    }
    SDL_Color white = {255,255,255};
    for(i = 0; i < r.sizeListText; i++){
        datas->surfaces->texts[i] = TTF_RenderText_Blended(datas->font, r.listText+i, white);;
        if(!datas->surfaces->texts[i]){
            fprintf(stderr,"Text Loading Error :/ -> %s\n", IMG_GetError());
            return 0;

        }
    }
    datas->surfaces->nbText = r.sizeListText;


    initLayouts(rendererP,datas);
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
    char titleWin[64];
    SDL_Event event;

    strcpy(titleWin, datas.projectName);
    strcat(titleWin, " ");
    strcat(titleWin, datas.version);
    SDL_SetWindowTitle(windowP, titleWin);
    SDL_SetWindowIcon(windowP, datas.surfaces->images[6]);

    datas.currentIRenderFct = menu_update;

    menu_init(&datas);
    datas.currentIEventsFct=menu_event;

    while (continuer)
    {
        updateEvent(event, windowP, rendererP,&datas, &continuer);
        updateRender(windowP, rendererP, datas);

    }
    return 0;

}

//Error
int errMemoryUnalloc(int sizeByte){
    fprintf(stderr, "! Allocation Bound Error :/ -> Cannot allocate %d bytes", sizeByte);
    return 0;
}


