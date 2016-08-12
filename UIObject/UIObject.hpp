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


#ifndef _UIOBJECT_HPP_
    #define _UIOBJECT_HPP_

#include<SDL2/SDL.h>

#define GRAVITY 2

class cTexture;

class cUIObject
{
  protected:
    //grid position of the object
        int m_xGrid;
        int m_yGrid;
        int m_yUpGrid; // origin point is lower left corner

    int m_x;
    int m_y;
    int m_width;
    int m_height;

    // util
    // let Y axis towards upper
    int UpperGridPositionY(int gridNum);

public:
    cUIObject();
    virtual ~cUIObject();

public:
    //x position= xGrid*xScale;
        static const int UNIT_X=32;
        static const int UNIT_Y=32;

        cTexture *m_tex;

    public:
        virtual void Draw()=0;

    friend class cPlayer;
};

#endif
