//
// Created by artyom on 10.01.19.
//

#ifndef UNTITLED1_MENUBUTTON_H
#define UNTITLED1_MENUBUTTON_H

#include "SDLGameObject.h"
class MenuButton : public SDLGameObject
{
public:

    MenuButton(const LoaderParams* pParams, void (*callback)());

    virtual void draw();
    virtual void update();
    virtual void clean();

private:
    enum button_state
    {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        CLICKED = 2
    };
    void (*m_callback)();
    bool m_bReleased;

};


#endif //UNTITLED1_MENUBUTTON_H
