#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>

#include "Clases/StateMenu.h"
#include "include/config.h"
#include "Clases/Fachada.h"


#define kUpdateTimePS 1000/60

int lvl = 1;

int main() {

  sf::RenderWindow  window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");
  window.setFramerateLimit(60); //forzamos a 60fps
  Fachada *Fachada= Fachada::Instance(&window);
  State *state= StateMenu::Instance();
  int estado;

//Creamos un reloj para el bucle...
  sf::Clock relojUpdate;

  float startClock = relojUpdate.getElapsedTime().asMilliseconds();
  sf::Time timeElapsed;

  char accion='\0';

  //Bucle del juego
  while (window.isOpen()) {
    //Bucle de obtención de eventos

      if(relojUpdate.getElapsedTime().asMilliseconds() >kUpdateTimePS){
        accion = Fachada->getInput();
        timeElapsed = relojUpdate.restart();
        state->update(accion, state, timeElapsed.asMilliseconds());

      }
      Fachada->clear();
      float percentTick = std::min(1.f, (float) relojUpdate.getElapsedTime().asMilliseconds()/kUpdateTimePS);
      state->render(percentTick);
      Fachada->display();
  }


  

  return 0;
}