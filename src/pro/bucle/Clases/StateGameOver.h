#ifndef STATEDIALOGO1_H
#define STATEDIALOGO1_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "StateMenu.h"
#include "Sprite.h"

class StateGameOver : public State {
public:
    static StateGameOver* Instance(int lvl, Player* player);
    ~StateGameOver();

    void render(float percentTick) override;
    void update(char accion, State*& estado, float time) override;

private:
    StateGameOver(int lvl,Player* player);
    static StateGameOver* pinstance;
    Player* player;
    Sprite* fondo;
    int lvl;
};

#endif // STATEDIALOGO1_H
