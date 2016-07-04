/// *********************16/02/2013***********************///


#include "DisplayManager.hpp"
#include "global.hpp"
#include "IntroState.hpp"

cDisplayManager::cDisplayManager()
{
    Global::window=SDL_CreateWindow("hello", 100, 100, Global::screen_width, Global::screen_height, SDL_WINDOW_SHOWN);
    Global::renderer=SDL_CreateRenderer(Global::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    cIntroState *p_intro=new cIntroState;
    p_intro->OnInit();
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
