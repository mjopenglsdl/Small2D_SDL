//
//  Label.cpp
//  Small2D_SDL
//
//  Created by minjie on 27/07/16.
//  Copyright © 2016 minjie. All rights reserved.
//

#include "Label.hpp"


cLabel::cLabel(int x, int y)
{
    m_x=x;
    m_y=y;
    m_width=160;
    m_height=30;
    
//    m_tex=NULL;
//    m_tex=ImageFunc::LoadSprites("Images/btn.png",true,255,0,0);
}

cLabel::~cLabel()
{
    
}