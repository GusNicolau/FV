#pragma once

#include <iostream>
#include "Sprite.h"

enum tipo { boton, puerta, mapa, chispas1, chispas2 };
enum estado { pulsado, noPulsado, bloqueada, cerrada, abierta, salida, salidaAbierta ,noRecogido, recogido, apagadas, encendidas };

class Objeto {
    private:

        Sprite* sprite;
        tipo type;
        estado state;
        int posX, posY;
        char orientacion;

    public: 

        Objeto(tipo, int, int, char);
        ~Objeto();
        void setPosition(int, int);
        void setState(estado);
        void setSprite();
        char getTipo();
        void interruptor();
        estado getState();
        Sprite* getSprite();
        void setAltSprite();
        

};