//
// Created by artyom on 30.12.18.
//

#ifndef UNTITLED1_ENEMY_H
#define UNTITLED1_ENEMY_H


#include "GameObject.h"
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:

    explicit Enemy(const LoaderParams* pParams);

    void draw() override;
    void update() override;
    void clean() override;
};


#endif //UNTITLED1_ENEMY_H
