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
#include "Wall.hpp"

#include "../Util/image_func.hpp"
#include "../Core/global.hpp"

#include "global.hpp"


cWall::cWall()
{
    m_tex=ImageFunc::LoadSprites("Images/tile.png");
}

cWall::~cWall()
{
    SDL_DestroyTexture(m_tex);
}


void cWall::Draw()
{
    for (int i=0; i<SCREEN_WIDTH_GRIDS ; i++) {
        ImageFunc::DrawTexture(UNIT_X*i, UpperGridPositionY(1) , m_tex);
    }
    
//        for(int j=3;j<7;j++)
//        {
////            ImageFunc::BlitSprites(j*XSCALE,8*YSCALE,img,Global::screen);
//        }
//
//        for(int j=4;j<8;j++)
//        {
////            ImageFunc::BlitSprites(j*XSCALE,14*YSCALE,img,Global::screen);
//        }
//
//        for(int j=10;j<16;j++)
//        {
////            ImageFunc::BlitSprites(j*XSCALE,10*YSCALE,img,Global::screen);
//        }
//
//    for(int i=0;i<2;i++)
//    {
//        for(int j=0;j<20;j++)
//        {
////            ImageFunc::BlitSprites(j*XSCALE,(18+i)*YSCALE,img,Global::screen);
//        }
//    }
}
