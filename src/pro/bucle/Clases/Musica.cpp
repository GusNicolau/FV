#include "Musica.h"

Musica::Musica(std::string archivo){

    if (!song.openFromFile(archivo)) {
        std::cerr << "Error al cargar la música" << std::endl;
        exit(0);
    } 
}


Musica::~Musica(){
    song.stop();
}

void Musica::setMusic(std::string archivo){
    song.stop();
    if (!song.openFromFile(archivo)) {
        std::cerr << "Error al cargar la música" << std::endl;
        exit(0);
    } 
}

void Musica::playMusic(){
    song.play();
    song.setLoop(true);
}

void Musica::stopMusic() {
    song.stop();
}
