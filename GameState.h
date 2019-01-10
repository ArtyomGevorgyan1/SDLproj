//
// Created by artyom on 10.01.19.
//

#ifndef UNTITLED1_GAMESTATE_H
#define UNTITLED1_GAMESTATE_H

#include <string>

class GameState {
public :

    virtual ~GameState(){};

    virtual void update() = 0;
    virtual void render() = 0;

    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;

    virtual std::string getStateID() const = 0;
};


#endif //UNTITLED1_GAMESTATE_H
