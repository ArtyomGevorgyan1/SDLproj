//
// Created by artyom on 30.12.18.
//

#ifndef UNTITLED1_TEXTUREMANAGER_H
#define UNTITLED1_TEXTUREMANAGER_H

#include "SDL_image.h"
#include "SDL2/SDL.h"
#include <string>
#include <map>

class TextureManager {
public:
    bool load(std::string fileName,std::string id, SDL_Renderer* pRenderer);

    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer,
            SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow,
            int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void clearFromTextureMap(std::string id)
    {
        m_textureMap.erase(id);
    }

    static TextureManager* Instance();
private:
    std::map<std::string, SDL_Texture*> m_textureMap;
    TextureManager() {};
    static TextureManager* s_pInstance;
};


typedef TextureManager TheTextureManager;


#endif //UNTITLED1_TEXTUREMANAGER_H
