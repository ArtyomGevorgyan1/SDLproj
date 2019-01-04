//
// Created by artyom on 02.01.19.
//

#include "InputHandler.h"
#include <iostream>
#include "Game.h"
#include "SDL2/SDL.h"


InputHandler* InputHandler::s_pInstance = 0;


void InputHandler::initialiseJoysticks()
{
    if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
    {
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }

    if(SDL_NumJoysticks() > 0)
    {
        for(int i = 0; i < SDL_NumJoysticks(); i++)
        {
            SDL_Joystick* joy = SDL_JoystickOpen(i);
            if(joy)
            {
                m_joysticks.push_back(joy);
            }
            else
            {
                std::cout << SDL_GetError();
            }
        }
        SDL_JoystickEventState(SDL_ENABLE);
        m_bJoysticksInitialised = true;

        std::cout << "Initialised "<< m_joysticks.size() << "joystick(s)";
    }
    else
    {
        std::cout << "NO DEVICE AVAILABLE\n";
        m_bJoysticksInitialised = false;
    }
}

void InputHandler::clean()
{
    if(m_bJoysticksInitialised)
    {
        for(unsigned int i = 0; i < SDL_NumJoysticks(); i++)
        {
            SDL_JoystickClose(m_joysticks[i]);
        }
    }
}

void InputHandler::update()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            //std::cout << "WANT TO QUIT\n";
            TheGame::Instance()->quit();
        }
    }
}