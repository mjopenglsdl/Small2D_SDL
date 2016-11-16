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
#include "PlayState.hpp"
#include "MenuState.hpp"
#include "FPSManager.hpp"
#include "GameManager.hpp"

#include "Wall.hpp"
#include "Player.hpp"

#include "UIObject.hpp"


cPlayState::cPlayState()
{
//m_tex_bg=ImageFunc::LoadSprites("./data/Images/play.png");

//init other members
    m_walls.clear();

// wall
    for (int i=0; i<cDisplayManager::SCREEN_WIDTH_GRIDS ; i++) {
        cWall *wall=new cWall(i,1);
        m_walls.push_back(wall);
        m_DisplayList.push_back(wall);
    }

    for (int i=0; i<4 ; i++) {
        cWall *wall=new cWall(i+4,2);
        m_walls.push_back(wall);
        m_DisplayList.push_back(wall);
    }

    for (int i=0; i<3 ; i++) {
        cWall *wall=new cWall(i+9,6);
        m_walls.push_back(wall);
        m_DisplayList.push_back(wall);
    }
///////

m_player=new cPlayer;

    cFPSManager::GetInstance()->StartCount();

    // add to display list
    m_DisplayList.push_back(m_player);
}


cPlayState::~cPlayState()
{
//    SDL_DestroyTexture(m_tex_bg);
}


void cPlayState::OnEvent()
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
                    cMenuState *p_menu=new cMenuState();
                    cGameManager::GetInstance()->PushState(p_menu);
                }

                else if(event.key.keysym.sym==SDLK_q)
                {
                    cGameManager::GetInstance()->PopState();
                }

                // movement
                else if (event.key.keysym.sym==SDLK_LEFT) {
                    m_player->m_xVel=-10;
                }
                else if(event.key.keysym.sym==SDLK_RIGHT){
                    m_player->m_xVel=10;
                }

                // jump
                else if(event.key.keysym.sym==SDLK_SPACE){
                    m_player->Jump();
                }

                break;

            case SDL_KEYUP:
                // movement
                if (event.key.keysym.sym==SDLK_LEFT) {
                    m_player->m_xVel=0;
                }
                else if(event.key.keysym.sym==SDLK_RIGHT){
                    m_player->m_xVel=0;
                }
                break;
            }

        }
}


void cPlayState::OnRender()
{
    SDL_RenderClear(cDisplayManager::GetInstance()->GetRenderer());

//    ImageFunc::DrawTexture(0, 0, m_tex_bg);

    for (unsigned int i=0; i<m_DisplayList.size(); i++)
    {
        m_DisplayList[i]->Draw();
    }

    SDL_RenderPresent(cDisplayManager::GetInstance()->GetRenderer());
}


void cPlayState::OnUpdate()
{
    cFPSManager::GetInstance()->CheckFPS();

    m_player->Update(cFPSManager::GetInstance()->m_deltaTime);

    for (unsigned int i=0; i<m_walls.size(); i++)
        {
        m_player->CheckCollision(m_walls[i]);
    }

    cFPSManager::GetInstance()->GetNewTick();
}

