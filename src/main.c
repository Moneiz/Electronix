#include <SDL2/SDL.h>
#include <stdio.h>

#include "iConception.h"
#include "kernel.h"

int main(int argc, char** argv)
{
    //SDL_Window* window = NULL;
    //SDL_Renderer* renderer = NULL;

    initWindow();
    updateApp();
    endApp();

    return 0;
}
