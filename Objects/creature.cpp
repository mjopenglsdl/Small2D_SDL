/// *********************16/02/2013***********************///


#include "object.hpp"
#include "movable_object.hpp"
#include "creature.hpp"

#include "../Util/image_func.hpp"
#include "../Core/global.hpp"

cCreature::cCreature()
{
    m_tex=ImageFunc::LoadSprites("Images/tile.png",true,255,0,0);
}

cCreature::~cCreature()
{
    SDL_DestroyTexture(m_tex);
}


void cCreature::Draw()
{
//            ImageFunc::BlitSprites(3*XSCALE,15*YSCALE,img,Global::screen);
}
