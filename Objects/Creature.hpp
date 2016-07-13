/// *********************16/02/2013***********************///
/* test creature class,
you can change the name/images to whatever you want
cObject->cMovableObject->cCreature
*/


#ifndef _CREATURE_HPP_
    #define _CREATURE_HPP_

class cObject;


class cCreature: public cObject
{
public:
    cCreature();
    ~cCreature();

public:
    void Draw();
    void Move(int xOffset);
    

};

#endif

