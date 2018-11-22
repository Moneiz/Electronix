#include "ressources.h"


Ressources getFilledRessources(char * configFile){


    Ressources r = {
        initConf(configFile),
        NB_IMAGES,
        {
            "./img/utils_new.png",                    //Images list
            "./img/utils_run.png",
            "./img/utils_stop.png",
            "./img/utils_exppng.png",
            "./img/utils_quit.png",
            "./img/commons_sq_bt.png",
            "./img/ico.png",
            "./img/fond.png"
        },
        NB_TEXT,
        {
            "Fil de cuivre",
            "Résistance",
            "Générateur",
            "Condensateur",
            "Diode",
            "DEL",
            "Inductance",
            "Transistor NPN",
            "Electronix",
            "Didacticiel",
            "Libre",
            "Quitter",
            "Sophie Pelluet - Alan Bretelle",
            "1",

        },
        "./fonts/Atures-700_PERSONAL_USE.ttf",  //Police
    };

    return r;
}
