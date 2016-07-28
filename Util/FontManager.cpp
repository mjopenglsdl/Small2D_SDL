//
//  FontManager.cpp
//  Small2D_SDL
//
//  Created by minjie on 28/07/16.
//  Copyright © 2016 minjie. All rights reserved.
//

#include "FontManager.hpp"

class FontManager
{
private:
    FontManager();
    ~FontManager();
    
    static FontManager *s_FontManager;
    
public:
    static FontManager *GetInstance();
};