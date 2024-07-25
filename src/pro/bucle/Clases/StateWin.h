#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "StateMenu.h"
#include "StateJuego.h"

using namespace std;

class StateWin : public State {
private:
    static StateWin* pinstance;
    StateWin(int, Player*);
    Player* player;
    Sprite* fondo;
    int lvl;

public:
    static StateWin* Instance(int,Player*);
    ~StateWin();
    void render(float);
    void update(char , State*&, float) override;
};