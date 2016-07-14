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
#include "global.hpp"
#include "../Util/image_func.hpp"
#include "../Util/FPSCounter.hpp"

#include "IntroState.hpp"
#include "PlayState.hpp"


int cIntroState::OnInit()
{
m_tex_bg=NULL;
m_tex_bg=ImageFunc::LoadSprites("Images/intro.png");
    m_fps=new cFPSCounter(25);
    m_fps->StartCount();

return 0;
}


int cIntroState::OnCleanUp()
{
    delete m_fps;
SDL_DestroyTexture(m_tex_bg);
return 0;
}


void cIntroState::OnEvent()
{
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                        Global::state.clear();   /// need cleanup !!!
                    break;
                case SDL_KEYDOWN:
                    {
                        if(event.key.keysym.sym==SDLK_y)
                        {
                            cPlayState *p_play=new cPlayState;
                            p_play->OnInit();
                            Global::state.push_back(p_play);
                        }

                       if(event.key.keysym.sym==SDLK_q)
                        {
                                Global::state.back()->OnCleanUp();
                                delete Global::state.back();
                                Global::state.pop_back();
                        }
                    }
                    break;
            } //end of switch

        } //end of event


}


void cIntroState::OnRender()
{
    SDL_RenderClear(Global::renderer);
    
    ImageFunc::DrawTexture(0, 0, m_tex_bg);
    
    SDL_RenderPresent(Global::renderer);
}


void cIntroState::OnUpdate()
{
    m_fps->CheckFPS();

    m_fps->GetNewTick();
return;
}
