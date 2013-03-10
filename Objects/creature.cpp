/// *********************16/02/2013***********************///


#include "object.hpp"
#include "movable_object.hpp"
#include "creature.hpp"

#include "../Util/image_func.hpp"
#include "../Core/global.hpp"

cCreature::cCreature()
{
    img=ImageFunc::LoadSprites("Images/HeroDown.bmp",true,255,0,0);
}

cCreature::~cCreature()
{
    SDL_FreeSurface(img);
}


void cCreature::Draw()
{
            ImageFunc::BlitSprites(3*XSCALE,15*YSCALE,img,Global::screen);
}
