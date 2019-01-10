//
// Created by artyom on 10.01.19.
//

#ifndef UNTITLED1_PLAYSTATE_H
#define UNTITLED1_PLAYSTATE_H

#include "GameState.h"
#include "GameObject.h"
#include <vector>

class PlayState : public GameState
{
public:

    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_playID; }

private:

    static const std::string s_playID;
    std::vector<GameObject*> m_gameObjects;
};

#endif //UNTITLED1_PLAYSTATE_H
