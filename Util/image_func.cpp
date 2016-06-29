
#include <SDL2_image/SDL_image.h>

#include "image_func.hpp"

// load images from file to the SDL_surface memory
SDL_Surface* ImageFunc::LoadSprites(const char* filemame,bool alpha,int r, int g, int b)
{
        SDL_Surface* old_image=NULL;
        SDL_Surface* new_image=NULL;

        old_image=IMG_Load(filemame);

//        new_image=SDL_DisplayFormat(old_image);
        SDL_FreeSurface(old_image);

        if(alpha)
        {
//            SDL_SetColorKey( new_image, SDL_SRCCOLORKEY, SDL_MapRGB( new_image->format,r, g,b ) );
        }


        return new_image;
}



int ImageFunc::BlitSprites(int dx, int dy, SDL_Surface*src, SDL_Surface*des, bool clip,int cx, int cy,int cw, int ch)
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
            SDL_BlitSurface(src,&rc_s,des,&rc_d);

        }

        else

        SDL_BlitSurface(src,0,des,&rc_d);

        return 0;
}







