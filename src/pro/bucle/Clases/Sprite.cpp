#include "Sprite.h"

Sprite::Sprite(std::string archivo, int coordX, int coordY, int sizeX, int sizeY, float scale, int posX, int posY){
    this->sizeX=sizeX;
    this->sizeY=sizeY;
    this->scaleX=scale;
    this->scaleY=scale;

    if (!textura.loadFromFile(archivo)) {
        std::cerr << "Error cargando textura en createSprites de la clase Sprite";
        exit(0);
    }

    sprite = sf::Sprite(textura);
    sprite.setTextureRect(sf::IntRect(coordX, coordY, sizeX, sizeY)); 
    sprite.setOrigin(sizeX/2, sizeY/2);
    sprite.setScale(scale, scale);
    sprite.setPosition(posX, posY);
}


void Sprite::setPosition(int posX, int posY){
    this->sprite.setPosition(posX, posY);
}

void Sprite::setOrigin(int x, int y){
    this->sprite.setOrigin(x,y);
}

void Sprite::setTexture(int coordX, int coordY, int sizeX, int sizeY){
    this->sprite.setTextureRect(sf::IntRect(coordX, coordY, sizeX, sizeY)); 
    this->sprite.setOrigin(sizeX/2, sizeY/2);   
}

void Sprite::move(int posX, int posY){
    this->sprite.move(posX, posY);
}

sf::Sprite Sprite::getSprite(){
    return sprite;
}

int Sprite::getPositionX() {
    return sprite.getPosition().x;
}

int Sprite::getPositionY() {
    return sprite.getPosition().y;
}

int Sprite::getWidth() {
    return sprite.getTextureRect().width;
}

int Sprite::getHeight() {
    return sprite.getTextureRect().height;
}
