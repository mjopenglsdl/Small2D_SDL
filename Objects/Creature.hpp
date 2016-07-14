/// *********************16/02/2013***********************///
/* test creature class,
you can change the name/images to whatever you want
cObject->cMovableObject->cCreature
*/


#ifndef _CREATURE_HPP_
    #define _CREATURE_HPP_

class cObject;

typedef enum{
    Move_NONE,
    Move_LEFT,
    Move_RIGHT
}eMoveDirection;


class cCreature: public cObject
{
public:
    cCreature();
    ~cCreature();

public:
    void Draw();
    void Update(int deltaTime);
    
    void Move(eMoveDirection dir);
    void Jump();
    
private:
    int m_baseHeight;
    bool m_bJump;
    int m_jumpVelocity;
    eMoveDirection m_eMoveDirection;
};


#endif