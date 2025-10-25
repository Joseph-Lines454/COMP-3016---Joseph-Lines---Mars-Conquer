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
    std::wstring title = L"A Evil SpaceMan";
    MainMenu* gameNew = new MainMenu("EvilSpaceMan", windowWidth, windowHeight,0);
    TTF_Font* newFont = TTF_OpenFont("Assets/Fonts/RubikGlitch-Regular.ttf", 80);
    if (newFont == NULL)
    {
        std::cout << "This did not work!" << std::endl;
    }

    gameNew->RenderFont(title, newFont, &windowWidth, &windowHeight);
    

    //Game Loop

    while (true)
    {
        gameNew->UpdateGame();
    }


    
}





