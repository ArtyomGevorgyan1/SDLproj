//
// Created by artyom on 02.01.19.
//

#ifndef UNTITLED1_INPUTHANDLER_H
#define UNTITLED1_INPUTHANDLER_H

#include "SDL.h"
#include <vector>

class InputHandler
{
public:

    void update();
    void clean();

    void initialiseJoysticks();

    bool joysticksInitialised() {
        return m_bJoysticksInitialised;
    }

private:

    InputHandler() {};
    ~InputHandler() {}

    static InputHandler* s_pInstance;

    std::vector<SDL_Joystick*> m_joysticks;
    bool m_bJoysticksInitialised;

public:
    static InputHandler* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new InputHandler();
        }

        return s_pInstance;
    }
};
typedef InputHandler TheInputHandler;

#endif //UNTITLED1_INPUTHANDLER_H
