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

#include <vector>

class Game
{
public:

    Game();
    ~Game();

    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

    void render();
    void update();
    void handleEvents();
    void clean();

    bool running() { return m_bRunning; }

private:

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    bool m_bRunning;

    int m_currentFrame;

/*
    GameObject m_go;
    Player m_player; */
    GameObject* m_go;
    GameObject* m_player;
    GameObject* m_enemy;


    std::vector<GameObject*> m_gameObjects;


};

#endif //UNTITLED1_GAME_H