
#include "Player.h"


Player::Player(int _x, int _y) {
    x = _x;
    y = _y;
    lastx= x;
    lasty=y;
    mapCount =0;
    vel = 0;
    jugado=false;

    std::srand(std::time(nullptr));

    //puertaFin = 5;
    puertaFin = std::rand() % 8 + 1;
    random = std::rand() % 4 + 1;
    //Y creo el spritesheet a partir de la imagen anterior
    sprite = new Sprite("resources/sprites.png",105,155,30,50,1,336,144);
    hitbox = new Sprite("resources/sprites.png",0,0,32,30,1,336,144);
    hitbox->setOrigin(16,9);
    sprite->setOrigin(15,36);

    music= new Musica("resources/saw.wav");

    reloj = new Reloj();
}

Player::~Player(){

    delete sprite;
    delete hitbox;
    delete music;
    delete reloj;
}

bool Player::getJugado() {
    return jugado;
}

void Player::setJugado() {
     jugado=true;
}

Musica* Player::getMusica() {
    return music;
}

Reloj* Player::getReloj() {
    return reloj;
}

Sprite* Player::getHitbox() {
    return hitbox;
}

Sprite* Player::getSprite() {
    return sprite;
}

int Player::getPuertaFin() {
    return puertaFin;
}

int Player::getRandom() {
    return random;
}

int Player::getX() {
    return x;
}

int Player::getLastX() {
    return lastx;
}

int Player::getY() {
    return y;
}

int Player::getLastY() {
    return lasty;
}

void Player::setX(int _x) {
    x = _x;
}
void Player::setLastX(int _x) {
    lastx = _x;
}


void Player::setY(int _y) {
    y = _y;
}

void Player::setLastY(int _y) {
    lasty = _y;
}

char Player::getMove() {
    return move;
}

void Player::setMove(char _move) {
    move = _move;
}

void Player::update(){
    lastx = x;
    lasty = y;
 }

void Player::mapCountUp() {
    mapCount++;
 }
void Player::mapCountDown() {
    mapCount--;
}

int Player::getMapCount() {
    return mapCount;
 }

float Player:: getVelocidad(){
    return vel;
 }

void Player:: setVelocidad(float v){
    vel = v;
 }