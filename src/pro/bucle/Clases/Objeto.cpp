#include "Objeto.h"

Objeto::Objeto(tipo type, int posX, int posY, char orientacion){

    this->orientacion = orientacion;
    this->type = type;
    switch (type)
    {
        case boton :
            state=noPulsado; 
            sprite = new Sprite("resources/boton.png",  0,  0,  32,  32,  1,  posX,  posY);
        break;
        case puerta :
            state=bloqueada; 
            if(orientacion=='H'){
                sprite = new Sprite("resources/puertaHorizontal.png",  0,  0,  128,  96,  1,  posX,  posY);
                sprite->setOrigin(16,16);
            }else if(orientacion== 'V'){
                sprite = new Sprite("resources/puertaVertical.png",  0,  0,  22,  128,  1,  posX,  posY);
                sprite->setOrigin(11,16);
            }
            
        break;
        case mapa :
            state=noRecogido;
            sprite= new Sprite("resources/map.png",  0,  0,  32,  32,  1,  posX,  posY);
        break;
        case chispas1 :
            state=encendidas;
            if(orientacion=='H'){
                sprite = new Sprite("resources/chispasHorizontal.png",  0,  0,  32,  32,  1,  posX,  posY);
            }else if(orientacion== 'V'){
                sprite = new Sprite("resources/chispasVertial.png",  0,  0,  32,  32,  1,  posX,  posY);
            }
        break;
        case chispas2 :
            state=encendidas;
            if(orientacion=='H'){
                sprite = new Sprite("resources/chispasHorizontal.png",  32,  0,  32,  32,  1,  posX,  posY);
            }else if(orientacion== 'V'){
                sprite = new Sprite("resources/chispasVertial.png",  32,  0,  32,  32,  1,  posX,  posY);
            }
        break;
    }

}

Objeto::~Objeto(){
    delete sprite;
}


void Objeto::setPosition(int x, int y){
    sprite->setPosition(x, y);
}

void Objeto::setState(estado sta){
    state = sta;
}

estado Objeto::getState(){
    return state;
}

char Objeto::getTipo(){
    char t = 'Q';
    switch (type)
    {
        case boton :
        t = 'B';
        break;
        case puerta :
        t = 'P';
        break;
        case mapa :
        t = 'M';
        break;
        case chispas1 :
        t = 'C';
        break;
        case chispas2 :
        t = 'C';
        break;
    }
    return t;
}

Sprite* Objeto::getSprite(){
    return sprite;
}

void Objeto::interruptor(){
    if(state==encendidas){
        state=apagadas;
    }else if(state==apagadas){
        state=encendidas;
    }
}

void Objeto::setAltSprite(){
        switch (type)
    {
        case boton :
            if(state==noPulsado){
                sprite->setTexture(32,0,32,32);
            }
        break;
        case puerta :
            if(state==bloqueada || state==salida ){
                if(orientacion=='H'){
                    sprite->setTexture(0,96,128,96);
                    sprite->setOrigin(16,16);
                }else if(orientacion=='V'){
                    sprite->setTexture(22,0,22,128);
                    sprite->setOrigin(11,16);
                }
            }else if(state==cerrada || state==salidaAbierta){
                if(orientacion=='H'){
                    sprite->setTexture(0,192,128,96);
                    sprite->setOrigin(16,16);
                }else if(orientacion=='V'){
                    sprite->setTexture(44,0,22,128);
                    sprite->setOrigin(11,16);
                }
            }
        break;
        case mapa :
        break;
    }
}