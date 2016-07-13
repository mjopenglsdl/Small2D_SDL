/// *********************16/02/2013***********************///


#include "Object.hpp"
#include "CollisionObject.hpp"
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
