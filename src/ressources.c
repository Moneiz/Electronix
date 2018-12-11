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
            "./img/fond.png",
            "./img/m_generator.png",
            "./img/m_wire.png",
            "./img/m_resistor.png",
            "./img/m_wire_corner.png",
            "./img/m_capacitor.png",
            "./img/m_wire_tri.png",
            "./img/m_wire_qua.png"
        },
        NB_TEXT,
        {
            "Electronix",
            "Didacticiel",
            "Libre",
            "Quitter",
            "Sophie Pelluet - Alan Bretelle",
            "1",
            "Générateur",
            "Fil de cuivre",
            "Résistance",
            "Condensateur"

        },
        "./fonts/Atures-700_PERSONAL_USE.ttf",  //Police
    };

    return r;
}
void fillModuleList(Module* module){
    module[0] = (Module) {1, 6, 8,2, generator_drawComponent, generator_calculate};
    module[1] = (Module) {2, 7, 9,4, wire_drawComponent, NULL};
    module[2] = (Module) {3, 8, 10,2, resistor_drawComponent, NULL};
    module[3] = (Module) {4, 9, 12,2, capacitor_drawComponent, NULL};
}

