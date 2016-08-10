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


#include "Wall.hpp"

#include "image_func.hpp"
#include "DisplayManager.hpp"

cWall::cWall()
{
    m_tex=ImageFunc::LoadSprites("Images/tile.png");
}

cWall::cWall(int xGrid, int yUpGrid)
{
    m_tex=ImageFunc::LoadSprites("Images/tile.png");
    m_xGrid=xGrid;
    m_yUpGrid=yUpGrid;

    m_x=m_xGrid*UNIT_X;
    m_y=(cDisplayManager::SCREEN_HEIGHT_GRIDS-m_yUpGrid)*UNIT_Y;
}

cWall::~cWall()
{

}


void cWall::Draw()
{
        ImageFunc::DrawTexture(UNIT_X*m_xGrid, UpperGridPositionY(m_yUpGrid) , m_tex);
}
