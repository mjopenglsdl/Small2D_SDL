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


#include "../UIObject.hpp"
#include "Player.hpp"

#include "../../Util/image_func.hpp"
#include "../../Core/DisplayManager.hpp"

#include <iostream>
using namespace std;

cPlayer::cPlayer()
{
    m_baseHeight=UpperGridPositionY(2);     //  base height h=0
    m_bJump=false;

    m_jumpVelocity=0;

    m_tex=ImageFunc::LoadSprites("Images/teddy.png",true,255,0,0);
    m_x=0;
    m_y=m_baseHeight;

    m_xVel=0;
    m_yVel=0;

    m_bCollided_X=false;
    m_bCollided_Y=false;
}

cPlayer::~cPlayer()
{

}


void cPlayer::Draw()
{
    ImageFunc::DrawTexture(m_x, m_y, m_tex);
}

void cPlayer::Update(int deltaTime)
{
    m_x+=m_xVel;
    m_y+=m_yVel;

    if(m_x<0 || m_x+ PLAYER_WIDTH>cDisplayManager::SCREEN_WIDTH || m_bCollided_X)
    {
        m_x-=m_xVel;
    }

    // reset
    m_bCollided_X=false;
    m_bCollided_Y=false;
}


// util
void cPlayer::Jump()
{
    m_bJump=true;
}

void cPlayer::CheckCollision(cUIObject *obj)
{
    int selfTop=m_y;
    int selfBtm=m_y+PLAYER_WIDTH;
    int selfLeft=m_x;
    int selfRight=m_x+PLAYER_WIDTH;

    int objTop=obj->m_y;
    int objBtm=obj->m_y+PLAYER_WIDTH;
    int objLeft=obj->m_x;
    int objRight=obj->m_x+PLAYER_WIDTH;

//    cout<<selfRight<<endl;

    // fix y axis, check x axis
    if (!(selfBtm<=objTop || selfTop >objBtm)) {
        if (!(selfRight+m_xVel<objLeft || selfLeft+m_xVel>objRight)) {
            m_bCollided_X=true;
        }
    }

}
