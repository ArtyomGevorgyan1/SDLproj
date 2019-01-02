//
// Created by artyom on 30.12.18.
//

#include "Player.h"
#include <string>


Player::Player(const LoaderParams* pParams) :
        SDLGameObject(pParams)
{

}

void Player::draw()
{
    SDLGameObject::draw(); // we now use SDLGameObject
}

void Player::update()
{
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

    m_acceleration.setX(1);

    SDLGameObject::update();
}

void Player::clean()
{
}
