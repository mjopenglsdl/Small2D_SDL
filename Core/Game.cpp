/// *********************16/02/2013***********************///

#include "Game.hpp"
#include "DisplayManager.hpp"

#include <SDL2_image/SDL_image.h>


cGame::cGame()
{
    SDL_Init( SDL_INIT_EVERYTHING);
    
    // other libs
    IMG_Init(IMG_INIT_PNG);
}

cGame::~cGame()
{
    SDL_Quit();
    
    IMG_Quit();
    printf("Exited cleanly\n");
}


int cGame::OnInitCmd()
{
return 0;
}


int cGame::OnInitGlobal()
{
return 0;
}


int cGame::Run()
{
    //init, cmd_line stuff

//init other global vari


    //display code
    cDisplayManager display_manager;
    display_manager.Display();


return 0;
}



