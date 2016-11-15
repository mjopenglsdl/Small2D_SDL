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

/* The Game core class used to run the game
you can manage the whole game, do cmd stuffs here
*/

#ifndef _GAMEMANAGER_HPP_
    #define _GAMEMANAGER_HPP_

#include <vector>
#include "GameState.hpp"

class cGameManager
{
    private:
        cGameManager(){};
        ~cGameManager(){};

        std::vector<cGameState*> m_states;

    public:
        void PushState(cGameState *state);
        void PopState();
        void ClearStates();

        int Init();
        int Run();   // From main, it enters here
        void CleanUp();


/// STATIC
private:
    static cGameManager *s_gameManager;
public:
    static cGameManager *GetInstance();
};


#endif
