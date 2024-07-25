#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "State.h"
#include "StateJuego.h"
#include "StateDialogo1.h" 


using namespace std;

class StateMenu : public State {
private:
    Player* player;
    static StateMenu* pinstance;
    StateMenu();
    StateMenu(Player*);
    ~StateMenu();
    StateMenu(const StateMenu &);
    StateMenu &operator= (const StateMenu &);
    Sprite* fondo;
    Sprite* boton;
    Sprite* finish;
    Sprite* flecha;
    Musica* menuMusic;

public:
    static StateMenu* Instance();
    static StateMenu* Instance(Player* p);
    void render(float percentTick);
    void update(char accion, State*& estado, float time);
    void stopMenuMusic();


};
