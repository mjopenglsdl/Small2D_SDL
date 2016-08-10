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


#include <SDL2/SDL.h>
#include "image_func.hpp"
#include "FPSManager.hpp"
#include "GameManager.hpp"
#include "DisplayManager.hpp"

#include "IntroState.hpp"
#include "PlayState.hpp"

#include "Button.hpp"
#include "Label.hpp"

#include <iostream>
#include <vector>

cIntroState::cIntroState()
{
    m_tex_bg=ImageFunc::LoadSprites("Images/intro.png");

    cFPSManager::GetInstance()->StartCount();

    /// UI
    m_btnStart = new cButton(cDisplayManager::SCREEN_WIDTH*0.5,cDisplayManager::SCREEN_HEIGHT*0.2);
    m_lblHello=new cLabel(cDisplayManager::SCREEN_WIDTH*0.5,cDisplayManager::SCREEN_HEIGHT*0.2+80);

    // add UI Object to the list
    m_DisplayList.push_back(m_btnStart);
    m_DisplayList.push_back(m_lblHello);
}


cIntroState::~cIntroState()
{
    SDL_DestroyTexture(m_tex_bg);
}


void cIntroState::OnEvent()
{
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    cGameManager::GetInstance()->ClearStates();
                    break;

                case SDL_KEYDOWN:
                    {
                       if(event.key.keysym.sym==SDLK_q)
                        {
                            cGameManager::GetInstance()->PopState();
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                {
                    if (m_btnStart->IsClicked(event.button.x, event.button.y)) {
                        cPlayState *p_play=new cPlayState();
                        cGameManager::GetInstance()->PushState(p_play);
                    }
                }
                break;
            } //end of switch

        } //end of event
}


void cIntroState::OnRender()
{
    SDL_RenderClear(cDisplayManager::GetInstance()->GetRenderer());

    ImageFunc::DrawTexture(0, 0, m_tex_bg);

    for (int i=0; i<m_DisplayList.size(); i++) {
        m_DisplayList[i]->Draw();
    }

    SDL_RenderPresent(cDisplayManager::GetInstance()->GetRenderer());
}


void cIntroState::OnUpdate()
{
    cFPSManager::GetInstance()->CheckFPS();

    cFPSManager::GetInstance()->GetNewTick();
return;
}
