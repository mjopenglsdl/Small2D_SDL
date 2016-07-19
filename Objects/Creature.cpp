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


#include "Object.hpp"
#include "Creature.hpp"

#include "../Util/image_func.hpp"
#include "../Core/global.hpp"

#include <iostream>
using namespace std;

cCreature::cCreature()
{
    m_baseHeight=UpperGridPositionY(2);     //  base height h=0
    m_bJump=false;
    
    m_jumpVelocity=0;
    
    m_tex=ImageFunc::LoadSprites("Images/teddy.png",true,255,0,0);
    m_xPosi=0;
    m_yPosi=m_baseHeight;
    
    m_xVel=0;
    m_yVel=0;
    
    m_bCollided=false;
}

cCreature::~cCreature()
{
    SDL_DestroyTexture(m_tex);
}


void cCreature::Draw()
{
    ImageFunc::DrawTexture(m_xPosi, m_yPosi, m_tex);
}

void cCreature::Update(int deltaTime)
{
    m_xPosi+=m_xVel;
    m_yPosi+=m_yVel;
    
    if(m_xPosi<0 || m_xPosi+ PLAYER_WIDTH>Global::screen_width || m_bCollided)
    {
        m_xPosi-=m_xVel;
    }
    
    m_bCollided=false;
}


// util
void cCreature::Jump()
{
    m_bJump=true;
}

void cCreature::CheckCollision(cObject *obj)
{
    int selfTop=m_yPosi;
    int selfBtm=m_yPosi+PLAYER_WIDTH;
    int selfLeft=m_xPosi;
    int selfRight=m_xPosi+PLAYER_WIDTH;
    
    int objTop=obj->m_yPosi;
    int objBtm=obj->m_yPosi+PLAYER_WIDTH;
    int objLeft=obj->m_xPosi;
    int objRight=obj->m_xPosi+PLAYER_WIDTH;
    
//    cout<<selfRight<<endl;
    
    if ( selfRight+m_xVel<=objLeft  || (selfLeft+m_xVel>= objRight) || (selfBtm+m_yVel<=objTop) || (selfTop+m_yVel>=objBtm)) {
        ;
    }else{
        m_bCollided=true;
    }
    
}

