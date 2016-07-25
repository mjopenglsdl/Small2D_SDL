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

#include "Button.hpp"
#include "image_func.hpp"

cButton::cButton(int x, int y)
{
    m_x=x;
    m_y=y;
    m_width=160;
    m_height=30;
    
    m_tex=NULL;
    m_tex=ImageFunc::LoadSprites("Images/btn.png",true,255,0,0);
}

cButton::~cButton(){
    SDL_DestroyTexture(m_tex);
}


void cButton::Draw()
{
    ImageFunc::DrawTexture(m_x, m_y, m_tex);
}

