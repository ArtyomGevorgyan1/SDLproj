//
// Created by artyom on 29.12.18.
//

#include "Game.h"
#include "InputHandler.h"
#include <iostream>

#include "MenuState.h"
#include "PlayState.h"

Game* Game::s_pInstance = 0;

Game::Game()
{

}

Game::~Game()
{

}

void Game::update()
{
    m_pGameStateMachine->update();
    std::cout << "im back\n";

}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    // attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos,
                                     width, height, flags);

        if(m_pWindow != 0) // window init success
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);


            if(m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer,
                                       255,0,0,255);

                m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));

                m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

                //TheInputHandler::Instance()->initialiseJoysticks();

                m_pGameStateMachine = new GameStateMachine();
                m_pGameStateMachine->changeState(new MenuState());


                if(!TheTextureManager::Instance()->load("../Assets/animate-alpha.png", "animate", m_pRenderer))
                {
                   return false;
                }

            }
            else
            {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }

    std::cout << "init success\n";
    m_bRunning = true; // everything inited successfully,
    //start the main loop

    return true;
}


void Game::render()
{
    //std::cout << "rendering\n";
    SDL_RenderClear(m_pRenderer); // clear to the draw colour

    m_pGameStateMachine->render();

    SDL_RenderPresent(m_pRenderer); // draw to the screen

}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    TheInputHandler::Instance()->clean();
    SDL_Quit();
}


void Game::handleEvents()
{
    TheInputHandler::Instance()->update();

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    {
        m_pGameStateMachine->changeState(new PlayState());
    }
}
