
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
class Sprite{


    private:
        sf::Texture textura;
        sf::Sprite sprite;
        int sizeX, sizeY;
        float scaleX, scaleY;
    
    public:
        
        Sprite(std::string archivo, int coordX, int coordY, int sizeX, int sizeY, float scale, int posX, int posY); 

        void setPosition(int posX, int posY);
        void setTexture(int cordX, int cordY, int sizeX, int sizeY);

        void setOrigin(int, int);
        void move(int posX, int posY);
        int getPositionX();
        int getPositionY();
        sf::Sprite getSprite();
        int getHeight();
        int getWidth();
};