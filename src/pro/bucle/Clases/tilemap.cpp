#include "tilemap.h"
using namespace tinyxml2;



Tilemap::Tilemap(int lvl){
    numBotones=0;
    XMLDocument doc;
    playerX=320;
    playerY =240;

    std::string filePath= "resources/mapaLab"+std::to_string(lvl)+".tmx";

    if (doc.LoadFile(filePath.c_str()) != XML_SUCCESS){
        std::cerr << "Failed to load map file: " << "resources/mapaSlide.tmx" << std::endl;
        exit(0);
    };

    //Tamaño del mapa y de los tiles
    XMLElement* map = doc.FirstChildElement("map");

    map->QueryIntAttribute("width", &_width);
    map->QueryIntAttribute("height", &_height);
    map->QueryIntAttribute("tilewidth", &_tileWidth);
    map->QueryIntAttribute("tileheight", &_tileHeight);

    //Imagen del tileset
    XMLElement *img = map->FirstChildElement("tileset")->FirstChildElement("image");
    const char *filename = img->Attribute("source");
    std::string path = "resources/";
    _tilesetTexture.loadFromFile(path+=filename);

    _tsw = _tilesetTexture.getSize().x / _tileWidth;
    _tsh = _tilesetTexture.getSize().y / _tileHeight;





    //contar numero de capas
    _numlayers=0;
    XMLElement *layer = map->FirstChildElement("layer");
    while(layer){
        _numlayers++;
        layer = layer->NextSiblingElement("layer");
    }

    //reservamos memoria _tilemap
    _tilemap = new int**[_numlayers];
    for(int i=0; i<_numlayers; i++){
        _tilemap[i]=new int*[_height];
        for(int y=0; y<_height; y++){
            _tilemap[i][y]=new int[_width];
        }
    }


    //reservamos memoria _tilemapSprite

    _tilemapSprite = new Sprite***[_numlayers];
    for(int i=0; i<_numlayers; i++){
        _tilemapSprite[i]=new Sprite**[_height];
        for(int y=0; y<_height; y++){
            _tilemapSprite[i][y]=new Sprite*[_width];
            for(int x=0; x<_width; x++){
                _tilemapSprite[i][y][x]=nullptr;
            }
        }
    }



    //Carga GIDs de multiples capas
    XMLElement *layerGID = map->FirstChildElement("layer");
    
    for(int l=0; l<_numlayers; l++){
        XMLElement* tile = layerGID->FirstChildElement("data")->FirstChildElement("tile");
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                if (tile->QueryIntAttribute("gid",  &_tilemap[l][y][x]) != XML_SUCCESS ){
                    _tilemap[l][y][x] = 0;     
                }

                //Avanzo al siguiente tag
                tile=tile->NextSiblingElement("tile");
            }
        }
        layerGID = layerGID->NextSiblingElement("layer");
    }


    //Creación del array de sprites
    for(int l=0; l<_numlayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                int gid = _tilemap[l][y][x]-1;

                if(gid>=_tsw*_tsh){
                    std::cout << "Error, gid at (l,x,y)= (" << l <<"," << x << "," << y << ") :" << gid << " fuera del rango del tileset (" <<_tsw*_tsh << ")" << std::endl;
                }else if(gid>=0){
                    //si fuera 0 no creo sprite

                    _tilemapSprite[l][y][x] = new Sprite(path, (gid % _tsw) * _tileWidth, (gid / _tsw) * _tileHeight, _tileWidth, _tileHeight, 1, x*_tileWidth+_tileWidth/2,  y*_tileHeight+_tileHeight/2);

                    if(l==2){
                         Objeto* obj = nullptr; 
                      switch (gid)
                        {
                           
                            case 35: //Puerta bloqueada Horizontal
                                obj = new Objeto(puerta, x*_tileWidth+_tileWidth/2,  y*_tileHeight+_tileHeight/2, 'H');
                            break;
                            case 39: //Puerta bloqueada Vertical
                                obj = new Objeto(puerta, x*_tileWidth+_tileWidth/2,  y*_tileHeight+_tileHeight/2, 'V');
                            break;
                            case 50: //chispas horizontales 1
                                obj = new Objeto(chispas1, x*_tileWidth+_tileWidth/2,  y*_tileHeight+_tileHeight/2, 'H');
                            break;
                            case 51: //chispas horizontales 2
                                obj = new Objeto(chispas2, x*_tileWidth+_tileWidth/2,  y*_tileHeight+_tileHeight/2, 'H');
                            break;
                            case 52: //chispas verticales 1
                                obj = new Objeto(chispas1, x*_tileWidth+_tileWidth/2,  y*_tileHeight+_tileHeight/2, 'V');
                            break;
                            case 53: //chispas verticales 2
                                obj = new Objeto(chispas2, x*_tileWidth+_tileWidth/2,  y*_tileHeight+_tileHeight/2, 'V');
                            break;
                            case 56: //Botón Desactivado
                                obj = new Objeto(boton, x*_tileWidth+_tileWidth/2,  y*_tileHeight+_tileHeight/2, 'H');
                                numBotones++;
                            break;
                            case 57: //Nota Mapa
                                obj= new Objeto(mapa, x*_tileWidth+_tileWidth/2,  y*_tileHeight+_tileHeight/2, 'H');
                            break;         
                            case 58: //Posición del personaje
                                playerX = x*_tileWidth+_tileWidth/2;
                                playerY= y*_tileHeight+_tileHeight/2;
                            break;                                                                                                    
                        }
                        if(obj){
                            objetos.push_back(obj);
                        }
                    }

                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                }else{
                    _tilemapSprite[l][y][x] = NULL;
                }
            }
        }
    }

}


Tilemap::~Tilemap(){
    if(_tilemap){
        for(int i=0; i<_numlayers; i++){
            for(int y=0; y<_height; y++){
                delete[] _tilemap[i][y];
            }
            delete[] _tilemap[i];
        }
        delete[] _tilemap;
    }

    if(_tilemapSprite){
        for(int i=0; i<_numlayers; i++){
            for(int y=0; y<_height; y++){
                for(int x=0; x<_width; x++){
                    delete _tilemapSprite[i][y][x];
                }
                delete _tilemapSprite[i][y];
            }
            delete _tilemapSprite[i];
        }
        delete _tilemapSprite;
    }

    for(auto obj : objetos){
        delete obj;
    }

}


void Tilemap::setActiveLayer(int layer){
    _activeLayer = layer;
}

Sprite**** Tilemap::getTilemap(){
    return _tilemapSprite;
}

int *** Tilemap::getTilemapGid(){
    return _tilemap;
}

int Tilemap::getHeight(){

    return _height;

}

int Tilemap::getWidth(){

    return _width;

}

int Tilemap::getNumlayers(){

    return _numlayers;

}

std::vector<Objeto*> Tilemap::getObjetos(){
    return objetos;
}

int Tilemap::getBotones(){
    return numBotones;
}

int Tilemap::getPlayerY(){
    return playerY;
}

int Tilemap::getPlayerX(){
    return playerX;
}