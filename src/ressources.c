#include "ressources.h"


Ressources getFilledRessources(){


    Ressources r = {
        NB_IMAGES,
        {
            "./img/test.jpg"
        },
        NB_TEXT,
        {
            "test wow"
        }

    };

    return r;
}
