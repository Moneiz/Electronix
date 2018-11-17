#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CONF_DEFINE
#define CONF_DEFINE

/**
Strcture contenant la configuration du programme
*/
typedef struct Config Config;
struct Config {

    int fullscreen;
    int maximized;
    int width;
    int height;

};

Config initConf(char * confFilename);

#endif // CONF_DEFINE
