#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "State.h"

using namespace std;

class StateDialogo1 : public State {
private:
    static StateDialogo1* pinstance;
    int lvl;
    Player* player;
    Sprite* fondo;
    int pulsado;

    StateDialogo1(int , Player*);
    ~StateDialogo1();
    StateDialogo1(const StateDialogo1 &);
    StateDialogo1 &operator= (const StateDialogo1 &);

public:
    static StateDialogo1* Instance(int, Player*);
    void render(float percentTick);
    void update(char accion, State*& estado, float time);
};
