//
// Created by artyom on 10.01.19.
//

#ifndef UNTITLED1_GAMESTATEMACHINE_H
#define UNTITLED1_GAMESTATEMACHINE_H

#include <vector>
#include "GameState.h"

class GameStateMachine
{
public:

    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();
    void update();
    void render();

private:

    std::vector<GameState*> m_gameStates;
};

#endif //UNTITLED1_GAMESTATEMACHINE_H
