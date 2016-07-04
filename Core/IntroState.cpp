/// *********************16/02/2013***********************///


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
    mp_fps=new cFPSCounter(25);
    mp_fps->StartCount();

return 0;
}


int cIntroState::OnCleanUp()
{
    delete mp_fps;
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
    mp_fps->CheckFPS();

    mp_fps->GetNewTick();
return;
}