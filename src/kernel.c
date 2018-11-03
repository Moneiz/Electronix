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
        fprintf(stdout,"Window Initialisation Error :/ -> %s\n",SDL_GetError());
        return NULL;
    }

    windowP = SDL_CreateWindow("Electronix",SDL_WINDOWPOS_UNDEFINED,
                                                            SDL_WINDOWPOS_UNDEFINED,
                                                            640,
                                                            480,
                                                            SDL_WINDOW_SHOWN);
    if(!windowP)
    {
        fprintf(stderr,"Window Creation Error :/ -> %s\n",SDL_GetError());
        return NULL;
    }

    return windowP;
}
void endApp(){
    SDL_DestroyWindow(windowP);
    SDL_Quit();
}
int updateApp(){
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }

}


