#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "State.h"
#include "StatePausa.h"
#include "StateMapa.h"
#include "StateGameOver.h"
#include "StateWin.h"
#include "tilemap.h"
#include "Objeto.h"
#include <chrono>
#include <thread>



class StateJuego:public State{

    private:

        static StateJuego* pinstance; 

        Player *player;
        Tilemap *map;
        Sprite* dialogo;
        Sprite* controles;
        int lvl, botonesPulsados, initMap;
        //funciones privadas
        StateJuego(int, Player*);
        ~StateJuego();
        StateJuego(const StateJuego &);
        StateJuego &operator= (const StateJuego &);

    public:
    
        //funciones heredadas
        static StateJuego* Instance();
        static StateJuego* Instance(int,Player*);
        void update(char accion, State* &, float);
        void updateObjetos(State* &, float );
        void render(float);
        void drawMap(int);
        bool comprobarColisionExt(char);
        char comprobarColisionMapa();
        Objeto*  comprobarObjeto();
        char colisionPuerta (float);
        int comprobarSuelo();
        int getLvl();
        void setLvl(int);
        
};