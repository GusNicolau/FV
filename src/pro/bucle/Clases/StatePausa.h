#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "State.h"
#include "StateJuego.h"


using namespace std;

class StatePausa:public State{

    private:
        int lvl;
        Player* player;
        static StatePausa* pinstance;
        StatePausa(int, Player*);
        ~StatePausa();
        StatePausa(const StatePausa &);
        StatePausa &operator= (const StatePausa &);
        Sprite* fondo;
        Sprite* boton;
        Sprite* finish;
        Sprite* flecha;

    public:
        static StatePausa* Instance();
        static StatePausa* Instance(int, Player*);
        void render(float percentTick);
        void update(char accion, State*& estado, float time);
};