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
    m_bCollided=false;
    m_jumpVelocity=JUMP_VELO_INIT; // init jump velo
    m_eMoveDirection=Move_NONE;
    
    m_tex=ImageFunc::LoadSprites("Images/teddy.png",true,255,0,0);
    m_xPosi=0;
    m_yPosi=m_baseHeight;
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
    if (!m_bCollided) {
        if (m_bJump) {
            m_jumpVelocity=m_jumpVelocity-GRAVITY*deltaTime;
            m_yPosi=m_yPosi-m_jumpVelocity*deltaTime;
            
            if (m_yPosi>=m_baseHeight) {
                m_yPosi=m_baseHeight;
                m_jumpVelocity=JUMP_VELO_INIT;
                m_bJump=false;
            }
        }
        
        if (Move_LEFT==m_eMoveDirection) {
            m_xPosi-=deltaTime*HORI_SPEED;
        }
        else if(Move_RIGHT==m_eMoveDirection){
            m_xPosi+=deltaTime*HORI_SPEED;
        }
    }
}


// util
void cCreature::Move(eMoveDirection direction)
{
    m_eMoveDirection=direction;
}


void cCreature::Jump()
{
    m_bJump=true;
}

void cCreature::CheckCollision(cObject *obj){
    // check 4 corners
    int objTop=obj->m_yPosi;
    int objBtm=obj->m_yPosi+PLAYER_WIDTH;
    int objLeft=obj->m_xPosi;
    int objRight=obj->m_xPosi+PLAYER_WIDTH;
//    cout<<"Top: "<<objTop<<"Bottom: "<<objBtm<<"Left: "<<objLeft<<"Right: "<<objRight<<endl;
    
    if (
        // bottom-right
        (m_xPosi+PLAYER_WIDTH >= objLeft && m_xPosi+PLAYER_WIDTH < objRight &&
        m_yPosi+PLAYER_WIDTH >= objTop && m_yPosi+PLAYER_WIDTH < objBtm)
        ||
        // bottom-left
        (m_xPosi >= objLeft && m_xPosi < objRight &&
         m_yPosi+PLAYER_WIDTH >= objTop && m_yPosi+PLAYER_WIDTH < objBtm)
        ||
        // top-left
        (m_xPosi >= objLeft && m_xPosi < objRight &&
         m_yPosi >= objTop && m_yPosi < objBtm)
        ||
        // top-right
        (m_xPosi+PLAYER_WIDTH >= objLeft && m_xPosi+PLAYER_WIDTH < objRight &&
         m_yPosi >= objTop && m_yPosi < objBtm)
        )
    {
        m_bCollided=true;
    }else{
        m_bCollided=false;
    }
}

