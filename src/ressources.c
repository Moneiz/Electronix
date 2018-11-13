#include "ressources.h"


Ressources getFilledRessources(){


    Ressources r = {
        NB_IMAGES,
        {
            "./img/test.jpg"                    //Images list
        },
        NB_TEXT,
        {
            "hello world!"                      //Texts list
        },
        "./fonts/Atures-700_PERSONAL_USE.ttf",  //Police
    };

    return r;
}
