//
// Created by artyom on 10.01.19.
//

#ifndef UNTITLED1_MENUSTATE_H
#define UNTITLED1_MENUSTATE_H

#include <vector>

#include "GameState.h"
#include "GameObject.h"

class MenuState : public GameState
{
public:

    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_menuID; }

private:

    static const std::string s_menuID;
    std::vector<GameObject*> m_gameObjects;

};

#endif //UNTITLED1_MENUSTATE_H
