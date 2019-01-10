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

    // not use the joystick to control the Player
    // if the joystick is not available, the sprite will stay on the screen and not move for now

    m_velocity.setX(0);
    m_velocity.setY(0);

    handleInput();

    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

    SDLGameObject::update();

    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

    //m_acceleration.setX(1);

}

void Player::clean()
{
}


void Player::handleInput()
{

    if(TheInputHandler::Instance()->getMouseButtonState(LEFT))
    {
        //m_velocity.setX(1);

        Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

        m_velocity = (*vec - m_position) / 100;
    }

}