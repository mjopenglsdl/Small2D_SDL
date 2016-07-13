/// *********************16/02/2013***********************///


#include "Object.hpp"
#include "MovableObject.hpp"
#include "Creature.hpp"

#include "../Util/image_func.hpp"
#include "../Core/global.hpp"

cCreature::cCreature()
{
    m_tex=ImageFunc::LoadSprites("Images/teddy.png",true,255,0,0);
}

cCreature::~cCreature()
{
    SDL_DestroyTexture(m_tex);
}


void cCreature::Draw()
{
    ImageFunc::DrawTexture(0, UpperPositionY(2) , m_tex);
}
