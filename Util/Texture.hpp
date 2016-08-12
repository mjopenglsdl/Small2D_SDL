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


#ifndef _TEXTURE_HPP_
    #define _TEXTURE_HPP_

#include<SDL2/SDL.h>

class cTexture
{
public:
    cTexture();
    ~cTexture();

    void LoadSprite(const char* filemame, bool alpha=false, int r=0, int g=0, int b=0);
    int Draw(int dx, int dy, bool clip=false, int cx=0, int cy=0,int cw=0, int ch=0);

public:
    SDL_Texture *m_tex;
};


#endif
