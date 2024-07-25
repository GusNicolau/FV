#pragma once

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Sprite.h"
#include "Reloj.h"
#include "Musica.h"


class Player{
    
    public:
     Player(int, int);
     ~Player();
     int getX();
     int getY();
     int getLastX();
     int getLastY();
     void setX(int);
     void setY(int);
     void setLastX(int);
     void setLastY(int);
     void update();
     char getMove();
     void setMove(char);
     void mapCountUp();
     int getMapCount();
     int getPuertaFin();
     int getRandom();
     void mapCountDown();
     float  getVelocidad();
     void   setVelocidad(float);
     Sprite* getHitbox();
     Sprite* getSprite();
     Reloj* getReloj();
     Musica* getMusica();
     bool getJugado();
     void setJugado();


    private:
     int x, y, lastx,lasty, mapCount, puertaFin, random;
     char move;
     float vel;
     bool jugado;
     Sprite* sprite;
     Sprite* hitbox;
     Reloj *reloj;
     Musica * music;
};