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


#include <SDL2_image/SDL_image.h>
#include <iostream>

#include "image_func.hpp"
#include "../Core/DisplayManager.hpp"


// load images from file to the SDL_surface memory
SDL_Texture* ImageFunc::LoadSprites(const char* filemame,bool alpha,int r, int g, int b)
{
    SDL_Texture *tex=IMG_LoadTexture(cDisplayManager::GetInstance()->GetRenderer(), filemame);

    if (!tex) {
        std::cout <<  " error: " << SDL_GetError() << std::endl;
    }

        if(alpha)
        {
//            SDL_SetColorKey( new_image, SDL_SRCCOLORKEY, SDL_MapRGB( new_image->format,r, g,b ) );
        }

        return tex;
}



int ImageFunc::DrawTexture(int dx, int dy, SDL_Texture*tex, bool clip,int cx, int cy,int cw, int ch)
{
    int w,h;
    SDL_QueryTexture(tex, 0, 0, &w, &h);

        SDL_Rect rc_d;
        rc_d.x=dx;
        rc_d.y=dy;

    rc_d.w=w;
    rc_d.h=h;

        if(clip)
        {
            SDL_Rect rc_s;
            rc_s.x=cx;
            rc_s.y=cy;
            rc_s.w=cw;
            rc_s.h=ch;
            SDL_RenderCopy(cDisplayManager::GetInstance()->GetRenderer() , tex, &rc_s, &rc_d);
        }

        else{
            SDL_RenderCopy(cDisplayManager::GetInstance()->GetRenderer() , tex, 0, &rc_d);
        }

        return 0;
}

