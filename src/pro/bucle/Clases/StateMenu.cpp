
#include "StateMenu.h"

StateMenu* StateMenu::pinstance = nullptr;

StateMenu::StateMenu(Player* p){
    menuMusic = new Musica("resources/menu.wav");
    menuMusic->playMusic();


    
    player=p;

    fondo = new Sprite("resources/Menu1.jpeg", 0, 0, 1600, 1244, 0.45f, 320, 240);
    boton = new Sprite("resources/start.jpeg", 0, 0, 185, 64, 0.45f, 320, 290);
    finish = new Sprite("resources/finish.jpeg", 0, 0, 175, 64, 0.45f, 320, 340);
    flecha = new Sprite("resources/flecha.jpeg", 0, 0, 75, 70, 0.45f, 240, 290);
}


StateMenu::StateMenu(){
    
    menuMusic = new Musica("resources/menu.wav");
    menuMusic->playMusic();

    player=nullptr;

    fondo = new Sprite("resources/Menu1.jpeg", 0, 0, 1600, 1244, 0.45f, 320, 240);
    boton = new Sprite("resources/start.jpeg", 0, 0, 185, 64, 0.45f, 320, 290);
    finish = new Sprite("resources/finish.jpeg", 0, 0, 175, 64, 0.45f, 320, 340);
    flecha = new Sprite("resources/flecha.jpeg", 0, 0, 75, 70, 0.45f, 240, 290);
}

StateMenu::~StateMenu() {
    delete fondo;
    delete boton;
    delete finish;
    delete flecha;
    delete menuMusic;
    pinstance = nullptr;
}

StateMenu* StateMenu::Instance() {
    if (pinstance == nullptr) {
        pinstance = new StateMenu();
    }
    return pinstance;
}

StateMenu* StateMenu::Instance(Player* p) {
    if (pinstance == nullptr) {
        pinstance = new StateMenu(p);
    }else{
        pinstance->player = p;
    }
    return pinstance; 
}



void StateMenu::render(float percentTick) {
    Fachada* fachada = Fachada::Instance(nullptr);
    if (!fachada) return;
    fachada->draw(fondo);
    fachada->draw(boton);
    fachada->draw(finish);
    fachada->draw(flecha);
}

void StateMenu::update(char accion, State*& estado, float time) {
    Fachada* fachada = Fachada::Instance(nullptr);

    if (!fachada) return;
    if (accion == 'Q') {
        
        StateMenu::~StateMenu();
        delete player;
        fachada->closeWindow();
    } else if (accion == 'I') {
        if(flecha->getPositionY() == boton->getPositionY()) {
            menuMusic->stopMusic();
            if(player==nullptr){
               
                player =new Player(336,144);
                estado = StateDialogo1::Instance(1,player);
                StateMenu::~StateMenu();
            }else{
                delete player;
                player =new Player(336,144);
                player->setJugado();
                player->getReloj()->changePause(true); 
                player->getMusica()->playMusic();
                estado = StateJuego::Instance(1,player);
                StateMenu::~StateMenu();
            }
        } else if(flecha->getPositionY() == finish->getPositionY()) {
            menuMusic->stopMusic();
            fachada->closeWindow();
        }
    } else if (accion == 'U') {
        if(flecha->getPositionY() == 340) {
            flecha->setPosition(flecha->getPositionX(), flecha->getPositionY() - 50);
        }
    } else if (accion == 'D') {
        if(flecha->getPositionY() == 290) {
            flecha->setPosition(flecha->getPositionX(), flecha->getPositionY() + 50);
        }
    }
}