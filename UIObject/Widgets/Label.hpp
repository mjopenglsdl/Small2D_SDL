//
//  Label.hpp
//  Small2D_SDL
//
//  Created by minjie on 27/07/16.
//  Copyright © 2016 minjie. All rights reserved.
//

#ifndef Label_hpp
#define Label_hpp

#include<SDL2/SDL.h>
#include "UIObject.hpp"

class cLabel: public cUIObject
{
public:
    cLabel(int x, int y);
    ~cLabel();
    
public:
    virtual void Draw();
    
private:
    SDL_Texture *m_tex;

};


#endif /* Label_hpp */
