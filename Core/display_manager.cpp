/// *********************16/02/2013***********************///


#include "display_manager.hpp"
#include "global.hpp"
#include "intro_state.hpp"

cDisplayManager::cDisplayManager()
{
//    Global::screen= SDL_SetVideoMode(Global::screen_width, Global::screen_height, 16,0);

    cIntroState *p_intro=new cIntroState;
    p_intro->OnInit();
    Global::state.push_back(p_intro);
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
