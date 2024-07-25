#include "StateGameOver.h"

StateGameOver* StateGameOver::pinstance = nullptr;

StateGameOver::StateGameOver(int lvl,Player* p) : lvl(lvl) {
    player=p;
    fondo = new Sprite("resources/gameover.jpeg", 0, 0, 1600, 1069, 0.45f, 320, 240);
}

StateGameOver::~StateGameOver() {
    delete fondo;
    pinstance = nullptr;
}

StateGameOver* StateGameOver::Instance(int lvl,Player* player) {
    if (pinstance == nullptr) {
        pinstance = new StateGameOver(lvl,player);
    }
    return pinstance;
}

void StateGameOver::render(float percentTick) {
    Fachada* fachada = Fachada::Instance(nullptr);
    if (!fachada) return;
    fachada->draw(fondo);
}

void StateGameOver::update(char accion, State*& estado, float time) {
    Fachada* fachada = Fachada::Instance(nullptr);
    if (!fachada) return;
    if (accion == 'I') {
            estado = StateMenu::Instance(player);
    }else if (accion == 'Q') {
        
        StateGameOver::~StateGameOver();
        delete player;
        fachada->closeWindow();
    } 
}
