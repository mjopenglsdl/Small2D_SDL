
#include <SDL2_image/SDL_image.h>
#include <iostream>

#include "image_func.hpp"
#include "global.hpp"


// load images from file to the SDL_surface memory
SDL_Texture* ImageFunc::LoadSprites(const char* filemame,bool alpha,int r, int g, int b)
{
    SDL_Texture *tex=IMG_LoadTexture(Global::renderer, filemame);
    
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
        SDL_Rect rc_d;
        rc_d.x=dx;
        rc_d.y=dy;

        if(clip)
        {
            SDL_Rect rc_s;
            rc_s.x=cx;
            rc_s.y=cy;
            rc_s.w=cw;
            rc_s.h=ch;
            SDL_RenderCopy(Global::renderer, tex, &rc_s, &rc_d);
        }

        else{
//            SDL_RenderCopy(Global::renderer, tex, 0, &rc_d);
             SDL_RenderCopy(Global::renderer, tex, 0, 0);
        }


        return 0;
}







