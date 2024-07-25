#pragma once

#include "State.h"
#include "StateJuego.h"
#include "Fachada.h"

class StateMapa : public State {

private:
    static StateMapa* pinstance;
    std::vector<Sprite*> mapas;
    Sprite* fondo;
    Sprite* sinMapas;
    int lvl;
    Player* player;
    StateMapa(int, Player*);
    ~StateMapa();

public:
    static StateMapa* Instance(int, Player*);
    virtual void update(char, State*&, float);
    virtual void render(float);
};
