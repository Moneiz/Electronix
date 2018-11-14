#include "ressources.h"


Ressources getFilledRessources(){


    Ressources r = {
        NB_IMAGES,
        {
            "./img/utils_new.png",                    //Images list
            "./img/utils_run.png",
            "./img/utils_stop.png",
            "./img/utils_exppng.png",
            "./img/utils_quit.png",
            "./img/commons_sq_bt.png",
            "./img/ico.png"
        },
        NB_TEXT,
        {
            "hello world!",                      //Texts list
            "bonjour"
        },
        "./fonts/Atures-700_PERSONAL_USE.ttf",  //Police
    };

    return r;
}
