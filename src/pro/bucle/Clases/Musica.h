
#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
class Musica{
    /*
        Clase que funciona como el Fachada del juego
        Aplicamos Singleton
    */


    private:
        ///variables
        sf::Music song;

    public:
        
        //constructores
        Musica(std::string archivo); 
        ~Musica();

        void setMusic(std::string);
        void playMusic();
        void stopMusic();
};