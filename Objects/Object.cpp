//
//  Object.cpp
//  Small2D_SDL
//
//  Created by minjie on 13/07/16.
//  Copyright © 2016 minjie. All rights reserved.
//

#include "Object.hpp"

#include "global.hpp"


int cObject::UpperGridPositionY(int gridNum){
    
    int finalPosiY=UNIT_Y*(SCREEN_HEIGHT_GRIDS-gridNum);
    return finalPosiY;
}
