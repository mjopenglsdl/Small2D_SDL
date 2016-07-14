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