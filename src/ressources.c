#include "ressources.h"


struct Ressources getFilledRessources(){

    struct Ressources r = {
        2,
        {
            "./img/test.jpg",
            "./img/NULL"
        }
    };
    return r;
}
