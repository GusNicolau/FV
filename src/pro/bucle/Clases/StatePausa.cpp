#include "StatePausa.h"

StatePausa* StatePausa::pinstance = nullptr;

StatePausa::StatePausa(int lvl,Player* p) {
    this->lvl=lvl;
    player =p;
    fondo = new Sprite("resources/Menu1.jpeg", 0, 0, 1600, 1244, 0.45f, 320, 240);
    boton = new Sprite("resources/start.jpeg", 0, 0, 185, 64, 0.45f, 320, 290);
    finish = new Sprite("resources/finish.jpeg", 0, 0, 175, 64, 0.45f, 320, 340);
    flecha = new Sprite("resources/flecha.jpeg", 0, 0, 75, 70, 0.45f, 240, 290);
}

StatePausa::~StatePausa() {
    delete fondo;
    delete boton;
    delete finish;
    delete flecha;
    pinstance = nullptr;
}

StatePausa* StatePausa::Instance(int lvl,Player* player) {
    if (pinstance == nullptr) {
        pinstance = new StatePausa(lvl,player);
    }
    return pinstance;
}

void StatePausa::render(float percentTick) {
    Fachada* fachada = Fachada::Instance(nullptr);
    if (!fachada) return;
    fachada->draw(fondo);
    fachada->draw(boton);
    fachada->draw(finish);
    fachada->draw(flecha);
}

void StatePausa::update(char accion, State*& estado, float time) {
    Fachada* fachada = Fachada::Instance(nullptr);
    if (!fachada) return;
    if (accion == 'Q') {
        StatePausa::~StatePausa();
        delete player;
        fachada->closeWindow();
    } else if (accion == 'I') {
        if(flecha->getPositionY() == boton->getPositionY()) {
            player->getReloj()->changePause(false); 
            estado = StateJuego::Instance(lvl, player);
        } else if(flecha->getPositionY() == finish->getPositionY()) {
            fachada->closeWindow();
        }
    } else if (accion == 'U') {
        if(flecha->getPositionY() == 340) {
            flecha->setPosition(flecha->getPositionX(), flecha->getPositionY() - 50);
        }
    } else if (accion == 'D') {
        if(flecha->getPositionY() == 290) {
            flecha->setPosition(flecha->getPositionX(), flecha->getPositionY() + 50);
        }
    }
}

