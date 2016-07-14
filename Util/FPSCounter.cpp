
#include "FPSCounter.hpp"
#include <SDL2/SDL.h>


void cFPSCounter::StartCount()
{
m_init_time=SDL_GetTicks();
}


void cFPSCounter::CheckFPS()
{
m_time_flag=SDL_GetTicks();
m_deltaTime=m_time_flag-m_init_time;

if(m_deltaTime<m_time_per_frame)
    SDL_Delay(m_time_per_frame-m_deltaTime);
}

void cFPSCounter::GetNewTick()
{
    m_init_time=SDL_GetTicks();
}
