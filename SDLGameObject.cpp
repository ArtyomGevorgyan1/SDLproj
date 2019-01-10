//
// Created by artyom on 02.01.19.
//

#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams), m_position(pParams->getX(), pParams->getY()),
                                                                    m_velocity(0, 0), m_acceleration(0, 0)
{
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextureID();

    m_currentRow = 1;
    m_currentFrame = 1;
}

/*
void SDLGameObject::draw()
{
    std::cout << "TRYING TO RENDER\n";

    TextureManager::Instance()->drawFrame(m_textureID,
                                          (int)m_position.getX(), (int)m_position.getY(), m_width,
                                          m_height, m_currentRow, m_currentFrame,
                                          TheGame::Instance()->getRenderer());
    std::cout << "SUCCESS\n";

}
 */



void SDLGameObject::draw()
{
    if(m_velocity.getX() > 0)
    {
        //std::cout << "TRYING TO RENDER\n";
        TextureManager::Instance()->drawFrame(m_textureID,
                                              (Uint32)m_position.getX(), (Uint32)m_position.getY(),
                                              m_width, m_height, m_currentRow, m_currentFrame,
                                              TheGame::Instance()->getRenderer(),SDL_FLIP_HORIZONTAL);
        //std::cout << "SUCCESS\n";
    }
    else
    {
        //std::cout << "TRYING TO RENDER\n";

        TextureManager::Instance()->drawFrame(m_textureID,
                                              (Uint32)m_position.getX(), (Uint32)m_position.getY(),
                                              m_width, m_height, m_currentRow, m_currentFrame,
                                              TheGame::Instance()->getRenderer());
        //std::cout << "SUCCESS\n";

    }
}

void SDLGameObject::clean() {}

void SDLGameObject::update()
{
    m_velocity += m_acceleration;
    m_position += m_velocity;
}