/// *********************16/02/2013***********************///


#include "global.hpp"
#include "PlayState.hpp"
#include "MenuState.hpp"
#include "../Util/image_func.hpp"
#include "../Util/FPSCounter.hpp"

#include "../Objects/Wall.hpp"
#include "../Objects/Creature.hpp"

#include "../Objects/Object.hpp"
#include "../Objects/CollisionObject.hpp"


int cPlayState::OnInit()
{
m_tex_bg=NULL;
//m_tex_bg=ImageFunc::LoadSprites("Images/play.png");

//init other members
m_wall=new cWall;
m_player=new cCreature;

    mp_fps=new cFPSCounter(25);
    mp_fps->StartCount();
return 0;
}


int cPlayState::OnCleanUp()
{
    delete m_wall;
    delete m_player;

    delete mp_fps;
    SDL_DestroyTexture(m_tex_bg);

    return 0;
}


void cPlayState::OnEvent()
{
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                Global::state.clear();
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_ESCAPE)
                {
                            cMenuState *p_menu=new cMenuState;
                            p_menu->OnInit();
                            Global::state.push_back(p_menu);
                }

                else if(event.key.keysym.sym==SDLK_q)
                {
                    Global::state.back()->OnCleanUp();
                    delete Global::state.back();
                    Global::state.pop_back();
                }
                 
                // movement
                else if (event.key.keysym.sym==SDLK_LEFT) {
                    m_player->Move(-5);
                }
                else if(event.key.keysym.sym==SDLK_RIGHT){
                    m_player->Move(5);
                }
                    
                break;
            }
        }
}


void cPlayState::OnRender()
{
    SDL_RenderClear(Global::renderer);
    
    ImageFunc::DrawTexture(0, 0, m_tex_bg);
    
    m_player->Draw();
    m_wall->Draw();
    
    SDL_RenderPresent(Global::renderer);
}


void cPlayState::OnUpdate()
{
    mp_fps->CheckFPS();

    mp_fps->GetNewTick();
}
