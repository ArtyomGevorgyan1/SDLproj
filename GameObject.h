//
// Created by artyom on 30.12.18.
//

#ifndef UNTITLED1_GAMEOBJECT_H
#define UNTITLED1_GAMEOBJECT_H

#include <iostream>
#include "SDL2/SDL.h"
#include "LoaderParams.h"


class GameObject
{
public:

    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;

protected:

    explicit GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}
};

#endif //UNTITLED1_GAMEOBJECT_H
