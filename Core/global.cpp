/// *********************16/02/2013***********************///


#include<SDL2/SDL.h>
#include "global.hpp"

#include "Object.hpp"


namespace Global
{
    SDL_Window *window=NULL;
    SDL_Renderer *renderer=NULL;
    
    int screen_width=cObject::UNIT_X*SCREEN_WIDTH_GRIDS;
    int screen_height=cObject::UNIT_Y*SCREEN_HEIGHT_GRIDS;

std::vector<cGameState*> state;

}
