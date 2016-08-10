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


#include "DisplayManager.hpp"

/// STATIC
cDisplayManager *cDisplayManager::s_displayManager=nullptr;

cDisplayManager *cDisplayManager::GetInstance()
{
    if (cDisplayManager::s_displayManager==nullptr) {
        cDisplayManager::s_displayManager=new cDisplayManager();
    }
    return cDisplayManager::s_displayManager;
}
///



void cDisplayManager::InitRes()
{
    m_window=SDL_CreateWindow("Small2D_SDL", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(!m_window)
    {

    }
    m_renderer=SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void cDisplayManager::ClearRes()
{
    SDL_DestroyRenderer(m_renderer); m_renderer=nullptr;
    SDL_DestroyWindow(m_window); m_window=nullptr;
}



