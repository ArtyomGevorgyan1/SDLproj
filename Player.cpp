//
// Created by artyom on 30.12.18.
//

#include "Player.h"
#include "InputHandler.h"
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

    m_velocity.setX(0);
    m_velocity.setY(0);

    handleInput();

    m_currentFrame = int(((SDL_GetTicks() / 100) % 5));

    SDLGameObject::update();

    m_currentFrame = int(((SDL_GetTicks() / 100) % 5));

    //m_acceleration.setX(1);

}

void Player::clean()
{
}

void Player::handleInput()
{
    Vector2D* target = TheInputHandler::Instance()
            ->getMousePosition();

    m_velocity = *target - m_position;

    m_velocity /= 50;
}