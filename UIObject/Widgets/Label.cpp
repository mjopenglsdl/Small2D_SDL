//
//  Label.cpp
//  Small2D_SDL
//
//  Created by minjie on 27/07/16.
//  Copyright © 2016 minjie. All rights reserved.
//

#include "Label.hpp"

#include "../../Util/FontManager.hpp"
#include "../../Util/image_func.hpp"


cLabel::cLabel(int x, int y)
{
    m_x=x;
    m_y=y;
    m_width=160;
    m_height=30;

    m_tex=NULL;
    m_tex=cFontManager::GetInstance()->GetTextureText("Hello World");
}

cLabel::~cLabel()
{

}


/// virtual
void cLabel::Draw()
{
    ImageFunc::DrawTexture(m_x, m_y, m_tex);
}
