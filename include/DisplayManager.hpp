/*
 * Copyright (c) 2011-2016 minjie.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

/*
    This class manages the display when the player enters the game
*/


#ifndef _DISPLAY_MANAGER_HPP_
    #define _DISPLAY_MANAGER_HPP_

#include <SDL2/SDL.h>
#include "UIObject.hpp"


class cDisplayManager
{
    private:
        cDisplayManager(){m_window=nullptr; m_renderer=nullptr;}
        ~cDisplayManager(){};

        SDL_Window *m_window;
        SDL_Renderer *m_renderer;

    public:
        void InitRes();
        void ClearRes();

    SDL_Renderer *GetRenderer() const {return m_renderer;}
    SDL_Window *GetWindow() const {return m_window;}

/// STATIC
private:
    static cDisplayManager* s_displayManager;
public:
    static cDisplayManager* GetInstance();

/// CONST
    static const int SCREEN_WIDTH_GRIDS=24;
    static const int SCREEN_HEIGHT_GRIDS=16;

    static const int SCREEN_WIDTH=cUIObject::UNIT_X*SCREEN_WIDTH_GRIDS;
    static const int SCREEN_HEIGHT=cUIObject::UNIT_Y*SCREEN_HEIGHT_GRIDS;
};


#endif
