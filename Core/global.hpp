/// *********************16/02/2013***********************///
/* This file contains the global variables to be
included into other cpp files
*/

#ifndef _GLOBAL_HPP_
    #define _GLOBAL_HPP_

#include "GameState.hpp"
#include <vector>
#include<SDL2/SDL.h>


#define SCREEN_WIDTH_GRIDS 24
#define SCREEN_HEIGHT_GRIDS 16


namespace Global
{
    
    extern SDL_Window *window;
    extern SDL_Renderer *renderer;
    
extern int screen_width;
extern int screen_height;

extern std::vector<cGameState*> state;

}


#endif