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


#include "GameManager.hpp"
#include "DisplayManager.hpp"
#include "../Util/FontManager.hpp"
#include "IntroState.hpp"

#include "../Util/Logger.hpp"

#include <SDL2_image/SDL_image.h>
#include <stdio.h>

/// STATIC
cGameManager *cGameManager::s_gameManager=nullptr;

cGameManager *cGameManager::GetInstance()
{
    if(nullptr==cGameManager::s_gameManager)
    {
        cGameManager::s_gameManager=new cGameManager();
    }
    return cGameManager::s_gameManager;
}
////


cGameManager::cGameManager()
{
    cLogger::GetInstance()->PrintLog(LogLevel_INFO, "SDL Start init...");

    SDL_Init( SDL_INIT_EVERYTHING);

    // other libs
    IMG_Init(IMG_INIT_PNG);

    // vari
    m_states.clear();
}


cGameManager::~cGameManager()
{
    cFontManager::GetInstance()->CleanUp();
    cDisplayManager::GetInstance()->ClearRes();
    IMG_Quit();
    SDL_Quit();

    printf("Exited cleanly\n");
}


int cGameManager::Run()
{
    //init, cmd_line stuff

//init other global vari


    cDisplayManager::GetInstance()->InitRes();
    // push first state
    cIntroState *p_intro=new cIntroState();
    m_states.push_back(p_intro);


    //states loop
    while (!m_states.empty())
    {
        m_states.back()->OnEvent();
        if (!m_states.empty())
            m_states.back()->OnRender();
        if (!m_states.empty())
            m_states.back()->OnUpdate();
    }

return 0;
}


/// states related
void cGameManager::ClearStates()
{
    while (!m_states.empty()) {
        delete m_states.back();
        m_states.pop_back();
    }
}

void cGameManager::PopState()
{
    delete m_states.back();
    m_states.pop_back();
}

void cGameManager::PushState(cGameState *state)
{
    m_states.push_back(state);
}
