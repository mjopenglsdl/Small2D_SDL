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


#include "FontManager.hpp"
#include "DisplayManager.hpp"


/// STATIC
cFontManager *cFontManager::s_fontManager=nullptr;

cFontManager *cFontManager::GetInstance()
{

    if (nullptr==cFontManager::s_fontManager) {
        cFontManager::s_fontManager=new cFontManager();
    }

    return cFontManager::s_fontManager;
}
///////



cFontManager::cFontManager()
{
    TTF_Init();
    m_defaultFont=TTF_OpenFont("./Fonts/ARIAL.TTF", DEFAULT_FONT_SIZE);
}

void cFontManager::CleanUp()
{
    TTF_CloseFont(m_defaultFont);
    TTF_Quit();
}


SDL_Texture *cFontManager::GetTextureText(const char *text)
{
    SDL_Surface *surf_text;
    SDL_Color fg;
    fg.r=0; fg.g=0; fg.b=255; fg.a=255;
    surf_text=TTF_RenderText_Solid(m_defaultFont, text, fg);

    SDL_Texture *tex_text=SDL_CreateTextureFromSurface(cDisplayManager::GetInstance()->GetRenderer() , surf_text);
    SDL_FreeSurface(surf_text);

    // tex needs to be freeed externally
    return tex_text;
}

