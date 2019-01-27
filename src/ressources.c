#include "ressources.h"


Ressources getFilledRessources(char * configFile){

    int i;
    char temp[64];
    //Remplit la structure des ressources
    Ressources r = {
        initConf(configFile),
        NB_IMAGES,
        {
            "utils_new.png",                    //Images list
            "utils_load.png",
            "utils_save.png",
            "utils_exppng.png",
            "utils_quit.png",       //5
            "commons_sq_bt.png",
            "ico.png",
            "fond.png",
            "m_generator.png",
            "m_wire.png",           //10
            "m_resistor.png",
            "m_wire_corner.png",
            "m_capacitor.png",
            "m_wire_tri.png",
            "m_wire_qua.png",       //15
            "m_transistor_npn.png",
            "m_transistor_pnp.png",
            "m_lamp.png",
            "m_diode.png",
            "m_del.png",            //20
            "m_switch_off.png"
        },
        NB_TEXT,
        {   //Info : les textes précédents d'un _ sont des textes dynamiques par convention
            "Electronix",
            "Tutorial",
            "Free mode",
            "Exit",
            "Sophie Pelluet - Alan Bretelle",
            "_nb",              //5
            "Generator",
            "Wire    ",
            "Resistor",
            "Capacitor",
            "Back  ",           //10
            "Load",
            "Save",
            "_file",
            "NPN Transistor",
            "PNP Transistor",   //15
            "Bulb   ",
            "Diode     ",
            "LED      ",
            "Switch  ",
            "_moduleInfo",       //20
            "Reverse"

        },
        "Atures-700_PERSONAL_USE.ttf",  //Police
    };

    //On ajoute le chemin contenant les images
    for(i = 0; i < r.sizeListImgFiles;i++){
        strcpy(temp, r.config.imgPath);
        strcat(temp, r.listImgFiles[i]);
        strcpy(r.listImgFiles[i], temp);
    }
    //On ajoute le chemin contenant la police
    strcpy(temp, r.config.fontsPath);
    strcat(temp, r.font);
    strcpy(r.font, temp);

    return r;
}
void fillModuleList(Module* module){
    //Charge les différents composants
    //id - id texte - id texture - nombre de liason max - pointeur de rendu - pointeur de calcul
    module[0] = (Module) {1, 6, 8,2, generator_drawComponent, generator_calculate};
    module[1] = (Module) {2, 7, 9,4, wire_drawComponent, NULL};
    module[2] = (Module) {3, 8, 10,2, resistor_drawComponent, NULL};
    module[3] = (Module) {4, 9, 12,2, capacitor_drawComponent, NULL};
    module[4] = (Module) {5, 14, 15, 3, NULL, NULL};
    module[5] = (Module) {6, 15,16,3, NULL, NULL};
    module[6] = (Module) {7, 16, 17, 2, bipole_drawComponent, NULL};
    module[7] = (Module) {8, 17, 18, 2, bipole_drawComponent, NULL};
    module[8] = (Module) {9, 18,19,2, bipole_drawComponent, NULL};
    module[9] = (Module) {10, 19, 20, 2, bipole_drawComponent, NULL};
}

