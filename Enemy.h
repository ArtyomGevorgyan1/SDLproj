//
// Created by artyom on 30.12.18.
//

#ifndef UNTITLED1_ENEMY_H
#define UNTITLED1_ENEMY_H


#include "GameObject.h"

class Enemy : public GameObject
{
public:

    void load(int x, int y, int width, int height, std::string
    textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();
};


#endif //UNTITLED1_ENEMY_H
