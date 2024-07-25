#include "Reloj.h"

int Reloj::kAlter = 0;
bool Reloj::kAlterInit = false;

Reloj::Reloj() {
    timer = sf::Clock();
    pausa = sf::Clock();
    kIncrease = 0;
    if(!kAlterInit) {
        kAlter = 0;
        kAlterInit = true;
    }
}


int Reloj::getTimeLeft(int chrono) {
    sf::Time contra = sf::seconds(chrono);
    return (1 + contra.asSeconds() -  timer.getElapsedTime().asSeconds() - kIncrease + kAlter);
}

bool Reloj::comprobarFin(int chrono) {
    sf::Time contra = sf::seconds(chrono);
    return ((timer.getElapsedTime().asSeconds() + kIncrease + kAlter) >= contra.asSeconds());
}

void Reloj::addTime(int add) {
    kIncrease += add;
}

void Reloj::changePause(bool p) {
    if(p){
        pausa.restart();
    }else{
        kAlter += (int)pausa.getElapsedTime().asSeconds();
    }
}