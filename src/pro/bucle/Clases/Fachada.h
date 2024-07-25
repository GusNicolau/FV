#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include "Sprite.h"
#include "Reloj.h"


enum Evento { 
    Closed, MouseButtonPressed, KeyPressed, KeyReleased, Scroll, MouseMove,
    Return, Up, Right, Left, Down, W, A, S, D, Escape, Q,
    E, F, N, Num1, Num2, Dash, Rshift, Space, 
    ScrollU, ScrollD
};

class Fachada {
    private:
        sf::RenderWindow* window;
        static Fachada* pinstance;
        Fachada(sf::RenderWindow *);
        Fachada(const Fachada &);
        Fachada &operator= (const Fachada &);

    public:
        static Fachada* Instance(sf::RenderWindow *);
        static Fachada* Instance();
        ~Fachada();
        void draw(Sprite *);
        void draw(sf::Sprite*);
        void draw(Reloj* reloj, int, int, int );
        void clear();
        void display();
        void setActive();
        void closeWindow();
        bool isPressed(char);
        bool colision(Sprite*, Sprite*);
        std::vector<Evento> pollEvents(sf::Event);
        char getInput();
};