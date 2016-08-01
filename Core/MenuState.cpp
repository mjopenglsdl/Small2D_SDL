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


#include "MenuState.hpp"
#include "../Util/image_func.hpp"

#include "GameManager.hpp"
#include "FPSManager.hpp"
#include "DisplayManager.hpp"


cMenuState::cMenuState()
{
    m_tex_bg=ImageFunc::LoadSprites("Images/menu.png");
    cFPSManager::GetInstance()->StartCount();
}


 cMenuState::~cMenuState()
{
    SDL_DestroyTexture(m_tex_bg);
}


void cMenuState::OnEvent()
{
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                cGameManager::GetInstance()->ClearStates();
                break;
                    
            case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_ESCAPE)
                {
                    cGameManager::GetInstance()->PopState();
                }
                break;
            }
        }
}


void cMenuState::OnRender()
{
    SDL_RenderClear(cDisplayManager::GetInstance()->GetRenderer());
    
    ImageFunc::DrawTexture(0, 0, m_tex_bg);
    
    SDL_RenderPresent(cDisplayManager::GetInstance()->GetRenderer());
}


void cMenuState::OnUpdate()
{
    cFPSManager::GetInstance()->CheckFPS();

    cFPSManager::GetInstance()->GetNewTick();
return;
}
