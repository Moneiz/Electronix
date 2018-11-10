#include "ressources.h"


Ressources getFilledRessources(){


    Ressources r = {
        NB_IMAGES,
        {
            "./img/test.jpg"
        },
        NB_TEXT,
        {
            "hello world!"
        }

    };

    return r;
}
