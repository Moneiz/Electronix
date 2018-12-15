#include "ressources.h"


Ressources getFilledRessources(char * configFile){


    Ressources r = {
        initConf(configFile),
        NB_IMAGES,
        {
            "./img/utils_new.png",                    //Images list
            "./img/utils_load.png",
            "./img/utils_save.png",
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
            "./img/m_wire_qua.png",
            "./img/m_transistor_npn.png",
            "./img/m_transistor_pnp.png",
            "./img/m_lamp.png",
            "./img/m_diode.png",
            "./img/m_del.png",
            "./img/m_switch_off.png"
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
            "Condensateur",
            "Retour",
            "Charger",
            "Sauver",
            "_file",
            "Transistor NPN",
            "Transistor PNP",
            "Ampoule",
            "Diode     ",
            "DEL      ",
            "Interrupteur",
            "_moduleInfo"

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
    module[4] = (Module) {5, 14, 15, 3, NULL, NULL};
    module[5] = (Module) {6, 15,16,3, NULL, NULL};
    module[6] = (Module) {7, 16, 17, 2, NULL, NULL};
    module[7] = (Module) {8, 17, 18, 2, NULL, NULL};
    module[8] = (Module) {9, 18,19,2, NULL, NULL};
    module[9] = (Module) {10, 19, 20, 2, NULL, NULL};
}

