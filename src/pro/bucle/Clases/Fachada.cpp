#include "Fachada.h"

Fachada::Fachada(sf::RenderWindow *window){
    this->window=window;
}

Fachada::~Fachada(){
    window = NULL;
    pinstance = NULL;
}

Fachada* Fachada::pinstance=nullptr;

Fachada* Fachada::Instance(sf::RenderWindow *window=nullptr){
    if(pinstance==0){
        pinstance=new Fachada
    (window);
    }
    return pinstance;
}

Fachada* Fachada::Instance(){
    return pinstance;
}

void Fachada::draw(Sprite *sprite){
    this->window->draw(sprite->getSprite());
}

void Fachada::draw(sf::Sprite* sprite) {
    if (window) {
        window->draw(*sprite);
    }
}

void Fachada::draw(Reloj* reloj, int left, int posX, int posY) {
    int timeLeft = reloj->getTimeLeft(left), minRest = timeLeft / 60, secRest, pixelX = 20, pixelY = 32;
    if(timeLeft % 60 == 0) secRest = 0;
    else secRest = timeLeft - minRest*60;

    int minLeft = minRest / 10, minRight;
    if(minRest % 10 == 0) minRight = 0;
    else minRight = minRest - minLeft * 10;

    int secLeft = secRest / 10, secRight;
    if(secRest % 10 == 0) secRight = 0;
    else secRight = secRest - secLeft * 10;

    Sprite *minL = new  Sprite("resources/00.png", 0, 0, pixelX, pixelY, 1, posX, posY);

    std::string stSprite;
    switch (minRight)
    {
    case 0:
        stSprite = std::string("resources/00.png");
        break;
    case 1:
        stSprite = std::string("resources/01.png");
        break;
    case 2:
        stSprite = std::string("resources/02.png");
        break;
    case 3:
        stSprite = std::string("resources/03.png");
    break;
    case 4:
        stSprite = std::string("resources/04.png");
    break;
    case 5:
        stSprite = std::string("resources/05.png");
        break;
    case 6:
        stSprite = std::string("resources/06.png");
        break;
    case 7:
        stSprite = std::string("resources/07.png");
        break;
    case 8:
        stSprite = std::string("resources/08.png");
        break;
    case 9:
        stSprite = std::string("resources/09.png");
        break;
    default:
        break;
    }
    posX += pixelX;
    Sprite *minR = new Sprite(stSprite, 0, 0, pixelX, pixelY, 1, posX, posY);

    posX += pixelX;
    Sprite *dots = new Sprite("resources/dots.png", 0, 0, pixelX, pixelY, 1, posX, posY);

    switch (secLeft)
    {
    case 0:
        stSprite = std::string("resources/00.png");
        break;
    case 1:
        stSprite = std::string("resources/01.png");
        break;
    case 2:
        stSprite = std::string("resources/02.png");
        break;
    case 3:
        stSprite = std::string("resources/03.png");
        break;
    case 4:
        stSprite = std::string("resources/04.png");
        break;
    case 5:
        stSprite = std::string("resources/05.png");
        break;
    case 6:
        stSprite = std::string("resources/06.png");
        break;
    case 7:
        stSprite = std::string("resources/07.png");
        break;
    case 8:
        stSprite = std::string("resources/08.png");
        break;
    case 9:
        stSprite = std::string("resources/09.png");
        break;
    default:
        break;
    }
    posX += pixelX;
    Sprite *secL = new Sprite(stSprite, 0, 0, pixelX, pixelY, 1, posX, posY);

    switch (secRight)
    {
    case 0:
        stSprite = std::string("resources/00.png");
        break;
    case 1:
        stSprite = std::string("resources/01.png");
        break;
    case 2:
        stSprite = std::string("resources/02.png");
        break;
    case 3:
        stSprite = std::string("resources/03.png");
        break;
    case 4:
        stSprite = std::string("resources/04.png");
        break;
    case 5:
        stSprite = std::string("resources/05.png");
        break;
    case 6:
        stSprite = std::string("resources/06.png");
        break;
    case 7:
        stSprite = std::string("resources/07.png");
        break;
    case 8:
        stSprite = std::string("resources/08.png");
        break;
    case 9:
        stSprite = std::string("resources/09.png");
        break;
    default:
        break;
    }
    posX += pixelX;
    Sprite *secR = new Sprite(stSprite, 0, 0, pixelX, pixelY, 1, posX, posY);

    draw(minL);
    draw(minR);
    draw(dots);
    draw(secL);
    draw(secR);
}


void Fachada::display() {
    if (window) {
        window->display();
    }
}

void Fachada::clear() {
    if (window) {
        window->clear();
    }
}

void Fachada::closeWindow() {
    if (window) {
        window->close();
    }
}

void Fachada::setActive() {
    if (window) {
        window->setActive();
    }
}

bool Fachada::isPressed(char accion){
    if (!window) return false;
    bool p = false;
    switch(accion){
        case 'L':
            p = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
            break;
        case 'R':
            p = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
            break;
        case 'U':
            p = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
            break;
        case 'D':
            p = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
            break;
    }
    return p;
}

char Fachada::getInput(){
    if (!window) return '\0';
    sf::Event event;
    char accion;
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                accion = 'Q';
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {

                //Mapeo del cursor
                case sf::Keyboard::Right:
                accion = 'R';
                break;

                case sf::Keyboard::Left:
                accion = 'L';
                break;

                case sf::Keyboard::Up:
                accion = 'U';
                break;

                case sf::Keyboard::Down:
                accion = 'D';
                break;

                //Tecla ESC para salir
                case sf::Keyboard::Escape:
                accion = 'Q';
                break;
                        //Tecla ESC para salir
                case sf::Keyboard::Return:
                accion = 'I';
                break;

                case sf::Keyboard::R:
                accion = 'K';
                break;

                case sf::Keyboard::M:
                accion = 'M';
                break;

                case sf::Keyboard::X:
                accion = 'X';
                break;

                //Cualquier tecla desconocida se imprime por pantalla su código
                default:
                std::cout << event.key.code << std::endl;
                break;
                }
        }
    }
  return accion;
}

bool Fachada::colision(Sprite* sp1, Sprite* sp2){
    bool c = false;
    if(sp1 != NULL && sp2 != NULL){
        c = sp1->getSprite().getGlobalBounds().intersects(sp2->getSprite().getGlobalBounds());
    }
    return c;
}