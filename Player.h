//
// Created by artyom on 30.12.18.
//

#ifndef UNTITLED1_PLAYER_H
#define UNTITLED1_PLAYER_H

#include "GameObject.h"
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:

    explicit Player(const LoaderParams* pParams);

    void draw() override;
    void update() override;
    void clean() override;
};

#endif //UNTITLED1_PLAYER_H
