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
#include "global.hpp"
#include "IntroState.hpp"


cDisplayManager::cDisplayManager()
{
    Global::window=SDL_CreateWindow("Small2D_SDL", 100, 100, Global::screen_width, Global::screen_height, SDL_WINDOW_SHOWN);
    Global::renderer=SDL_CreateRenderer(Global::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    cIntroState *p_intro=new cIntroState();
    Global::state.push_back(p_intro);
}


cDisplayManager::~cDisplayManager(){
    SDL_DestroyRenderer(Global::renderer);
    SDL_DestroyWindow(Global::window);
}


// Iterate through each game states
// don't modify this function
// you should focus on each function in specific states
int cDisplayManager::Display()
{
    while (!Global::state.empty())
    {
            Global::state.back()->OnEvent();
        if (!Global::state.empty())
            Global::state.back()->OnRender();
        if (!Global::state.empty())
            Global::state.back()->OnUpdate();
    }

   return 0;
}


int cDisplayManager::PushScreen()
{

return 0;
}


int cDisplayManager::PopScreen()
{

return 0;
}
