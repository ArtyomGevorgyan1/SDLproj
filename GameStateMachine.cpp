//
// Created by artyom on 10.01.19.
//

#include "GameStateMachine.h"
#include <iostream>

void GameStateMachine::pushState(GameState *pState)
{
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
    if(!m_gameStates.empty())
    {
        if(m_gameStates.back()->onExit())
        {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
}

void GameStateMachine::changeState(GameState *pState)
{
    if(!m_gameStates.empty())
    {
        if(m_gameStates.back()->getStateID() == pState->getStateID())
        {
            return; // do nothing
        }

        if(m_gameStates.back()->onExit())
        {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }

    // push back our new state
    m_gameStates.push_back(pState);

    // initialise it
    m_gameStates.back()->onEnter();

//    std::cout << "Chenged the stets\n";
}

void GameStateMachine::update()

{
    //std::cout << "here\n";
    if(!m_gameStates.empty())
    {
        m_gameStates.back()->update();
    }
    std::cout << "back\n";
}

void GameStateMachine::render()
{
    if(!m_gameStates.empty())
    {
        m_gameStates.back()->render();
    }
}