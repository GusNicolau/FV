#include "StateMapa.h"

StateMapa::StateMapa(int lvl, Player* p){
    this->lvl=lvl;
    player=p;

    fondo = new Sprite("resources/pausa.jpeg", 0, 0, 1600, 1244, 0.45f, 320, 240);
    sinMapas = new Sprite("resources/nota0-0.png", 0, 0, 640, 480, 1, 320, 240);
    std::string puerta= std::to_string(player->getPuertaFin());
    int r= player->getRandom();
    Sprite* mapaSprite= nullptr;
    for(int i= 0; i<4; i++ ){
        int suma = r+i;
        if(suma > 4){
            r=1;
            suma=1;
        }
         std::string mapa = std::to_string(suma);
        mapaSprite=  new Sprite("resources/nota"+ puerta +"-"+ mapa + ".png", 0, 0, 640, 480, 1, 320, 240);
        mapas.push_back(mapaSprite);

    }
}

StateMapa* StateMapa::pinstance = nullptr;

StateMapa::~StateMapa() {
    for(auto map : mapas){
        delete map;
    }
    pinstance = nullptr;
}

StateMapa* StateMapa::Instance(int lvl, Player* p) {
    if (pinstance == nullptr) { // Si aún no se ha creado
        pinstance = new StateMapa(lvl,p);
    }
    return pinstance; 

}

void StateMapa::update(char accion, State*& estado, float time) {
    Fachada* fachada = Fachada::Instance();
    
    switch (accion) {
        case 'Q':
            StateMapa::~StateMapa();
            delete player;
            fachada->closeWindow();
            break;
        case 'M':
            player->getReloj()->changePause(false); 
            estado = StateJuego::Instance(lvl, player);
            StateMapa::~StateMapa();
            break;
    }

}

void StateMapa::render(float percentTick) {
    Fachada* fachada = Fachada::Instance();
    fachada->draw(fondo);
    if(player->getMapCount()==0){
        fachada->draw(sinMapas);
    }else{
        for(int i=0; i<player->getMapCount();i++){
            fachada->draw(mapas[i]);
        }
    }
}
