#include "StateWin.h"

StateWin* StateWin::pinstance = nullptr;

StateWin::StateWin(int lvl,Player* p) : lvl(lvl) {
    player = p;
    fondo = new Sprite("resources/win.jpeg", 0, 0, 1537, 1188, 0.45f, 320, 240);
}

StateWin::~StateWin() {
    delete fondo;
    pinstance = nullptr;
}

StateWin* StateWin::Instance(int lvl,Player* player) {
    if (pinstance == nullptr) {
        pinstance = new StateWin(lvl,player);
    }
    return pinstance;
}

void StateWin::render(float percentTick) {
    Fachada* fachada = Fachada::Instance(nullptr);
    if (!fachada) return;
    fachada->draw(fondo);
}

void StateWin::update(char accion, State*& estado, float time) {
    Fachada* fachada = Fachada::Instance(nullptr);
    if (!fachada) return;
    if (accion == 'I') {
            estado = StateMenu::Instance(player);
    }else if(accion == 'Q') {
        StateWin::~StateWin();
        delete player;
        fachada->closeWindow();
    } 
}
