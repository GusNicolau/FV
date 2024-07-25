#include "StateDialogo1.h"
#include "StateJuego.h"

StateDialogo1* StateDialogo1::pinstance = nullptr;

StateDialogo1::StateDialogo1(int lvl, Player* p) : pulsado(0), lvl(lvl) {
    player=p;
    fondo = new Sprite("resources/conversacion1.png", 0, 0, 640, 480, 1, 320, 240);

}

StateDialogo1::~StateDialogo1() {
    delete fondo;
    pinstance = nullptr;
}

StateDialogo1* StateDialogo1::Instance(int lvl, Player* player) {
    if (pinstance == nullptr) {
        pinstance = new StateDialogo1(lvl, player);
    }
    return pinstance;
}

void StateDialogo1::render(float percentTick) {
    Fachada* fachada = Fachada::Instance(nullptr);
    if (!fachada) return;
    fachada-> draw(fondo);
}

void StateDialogo1::update(char accion, State*& estado, float time) {
    Fachada* fachada = Fachada::Instance(nullptr);
    if (!fachada) return;
    if (accion == 'I') {
        player->getReloj()->changePause(false);
        player->getMusica()->playMusic();
        estado = StateJuego::Instance(lvl,player);
        StateDialogo1::~StateDialogo1();
    }else if (accion == 'Q') {
        
        StateDialogo1::~StateDialogo1();
        delete player;
        fachada->closeWindow();
    } 
}
