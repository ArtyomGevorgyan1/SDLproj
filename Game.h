//
// Created by artyom on 29.12.18.
//

#ifndef UNTITLED1_GAME_H
#define UNTITLED1_GAME_H

#include "SDL2/SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

#include "GameStateMachine.h"

#include <vector>

class Game
{
public:
    ~Game();

    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();

    void quit() {
        //SDL_Quit();
        m_bRunning = false;
    }

    bool running() { return m_bRunning; }

    static Game* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }

        return s_pInstance;
    }

    SDL_Renderer* getRenderer() const { return m_pRenderer; }


private:

    // renderer and window pointers
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    // bool to make sure the game is supposed to go on
    bool m_bRunning;

    std::vector<SDLGameObject*> m_gameObjects;

    GameStateMachine* m_pGameStateMachine;

    // singleton part
    Game();
    static Game* s_pInstance;
};

// singleton part
typedef Game TheGame;

#endif //UNTITLED1_GAME_H
