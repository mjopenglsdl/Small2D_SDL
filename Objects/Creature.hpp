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


#ifndef _CREATURE_HPP_
    #define _CREATURE_HPP_

#include "Object.hpp"

typedef enum{
    Move_NONE,
    Move_LEFT,
    Move_RIGHT
}eMoveDirection;


class cCreature: public cObject
{
public:
    cCreature();
    ~cCreature();

public:
    void Draw();
    void Update(int deltaTime);
    
    void Move(eMoveDirection dir);
    void Jump();
    void CheckCollision(cObject *obj);
    
private:
    int m_baseHeight;
    bool m_bJump;
    int m_jumpVelocity;
    eMoveDirection m_eMoveDirection;
    
    // collison
    bool m_bTopCollided;
    bool m_bBtmCollided;
    bool m_bLeftCollided;
    bool m_bRightCollided;
    
private:
    // const
    static const int JUMP_VELO_INIT=24;
    static const int HORI_SPEED=7;
    static const int PLAYER_WIDTH=32;

};


#endif