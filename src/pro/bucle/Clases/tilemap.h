#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "tinyxml2.h"
#include "Objeto.h"


class Tilemap{

    public: 
        Tilemap(int);
        ~Tilemap();
        void setActiveLayer(int layer);
        Sprite **** getTilemap();
        int getPlayerX();
        int getPlayerY();
        int getHeight();
        int getWidth();
        int getNumlayers();
        int *** getTilemapGid();
        int getBotones();
        std::vector<Objeto *> getObjetos();
        


    private:

        Sprite ****_tilemapSprite;
        sf::Texture _tilesetTexture;
        std::vector<Objeto *> objetos;

        int ***_tilemap;
        int _numlayers, _width, _height, _tileWidth, _tileHeight, _activeLayer, _tsw, _tsh, numBotones, playerX, playerY;

};