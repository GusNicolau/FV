#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

class Reloj {
    private:
        sf::Clock timer;
        sf::Clock pausa; 
        int kIncrease;
        
        static int kAlter;
        static bool kAlterInit;

    public :
        Reloj();
        int getTimeLeft(int);
        bool comprobarFin(int);
        void addTime(int);
        void changePause(bool);
};