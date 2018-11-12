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
        },
        {
            "./fonts/Atures-700_PERSONAL_USE.ttf"
        }

    };

    return r;
}
