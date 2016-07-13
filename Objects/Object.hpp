/// *********************16/02/2013***********************///
/* Base class of the game object,
for example, human, wall, flower....
*/


#ifndef _OBJECT_HPP_
    #define _OBJECT_HPP_
#include<SDL2/SDL.h>

class cObject
{
  protected:
    //grid position of the object
        int m_xGrid;
        int m_yGrid;
    int m_xPosi;
    int m_yPosi;
    
    // util
    // let Y axis towards upper
    int UpperGridPositionY(int gridNum);
    
public:
    //x position= xGrid*xScale;
        static const int UNIT_X=32;
        static const int UNIT_Y=32;

        SDL_Texture *m_tex;
    
    public:

};

#endif
