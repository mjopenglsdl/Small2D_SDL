/* 
 Enters the game main loop, into function cGame::Run
*/


#include <SDL2/SDL.h>
#include "Core/game.hpp"


int main ( int argc, char** argv )
{
    cGame theGame;
    return theGame.Run();
}
