#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include "Fachada.h"
#include "Player.h"


class State{
    private:
        static State* pinstance;

    protected:
        State(){}
        State(const State &){}
        State &operator= (const State &){}
    
    public:
        virtual ~State(){}
        static State* Instance();
        virtual void update(char, State*&, float){}
        virtual void render(float){}
        virtual void reset(){}
};