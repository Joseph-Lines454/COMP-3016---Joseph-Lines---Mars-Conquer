#include "GameObject.h"
#include "SDL3/SDL.h"
#include <iostream>;
#include "Game.h"
#include "MainMenu.h"

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    

    //Creating a character system
   

    //gameOne->InputValues(new Physics());

   
    MainMenu* gameNew = new MainMenu("EvilSpaceMan", 600, 400,0);


    //Game Loop

    while (true)
    {
        gameNew->UpdateGame();
    }


    
}





