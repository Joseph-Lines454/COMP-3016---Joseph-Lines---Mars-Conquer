#include "GameObject.h"
#include "SDL3/SDL.h"
#include <iostream>;
#include "Game.h"
#include "MainMenu.h"
#include <SDL3_ttf/SDL_ttf.h>
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    

    //Creating a character system
   

    //gameOne->InputValues(new Physics());
    int windowWidth = 800;
    int windowHeight = 800;
    std::wstring title = L"Evil SpaceMan";
    MainMenu* gameNew = new MainMenu("EvilSpaceMan", windowWidth, windowHeight,0);
    
    gameNew->SetTitleText(L"Evil SpaceMan",8,2);
    gameNew->SetPressPlay(L"Click Any Key", 1, 1);
    
    //Current Game loop
    while (true)
    {
        gameNew->UpdateGame();
        if (gameNew->PlayButtonCheck())
        {
            //Some code that transports the user into the game - Let the user change window
        }

        
    }    
}





