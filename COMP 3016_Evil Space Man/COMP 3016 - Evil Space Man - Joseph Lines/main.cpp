#include "GameObject.h"
#include "SDL3/SDL.h"
#include <iostream>;
#include "Game.h"
#include "MainMenu.h"
#include <SDL3_ttf/SDL_ttf.h>
#include "Instructions.h"
#include <map>
int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();


    //Creating a character system


    //gameOne->InputValues(new Physics());
    int windowWidth = 800;
    int windowHeight = 800;
    std::wstring title = L"Evil SpaceMan";
    MainMenu* gameNew = new MainMenu("EvilSpaceMan", windowWidth, windowHeight, 0);

    gameNew->SetTitleText(L"Evil SpaceMan", 8, 2);
    gameNew->SetPressPlay(L"Click Any Key", 1, 1);

    //Current Game loop
    gameNew->UpdateGame();
    while (true)
    {
        
        if (gameNew->PlayButtonCheck())
        {
            //Some code that transports the user into the game - Let the user change window

            std::cout << "Now we are cooking with some gas HAHAH";
            break;
        }
    }
    //Cleanup


    SDL_Renderer* renderTemp = gameNew->GetRenderWindow();
    SDL_Window* windowTemp = gameNew->GetWindow();
    delete gameNew;
    Instructions* Instruction = new Instructions();
    Instruction->InstructionText(renderTemp);
    Instruction->UpdateGame();


    // Game Loop Now

    std::map <std::string, std::string> AssetsWalk = {{"Walking_One","Assets/SpaceMan_PNG/SpaceMan_East/Walking/Walk_One_East.bmp"},{"Walking_Two","Assets/SpaceMan_PNG/SpaceMan_East/Walking/Walk_Two_East.bmp"}
    ,{"Walking_Three","Assets/SpaceMan_PNG/SpaceMan_East/Walking/Walk_Three_East.bmp"},{"Walking_Four","Assets/SpaceMan_PNG/SpaceMan_East/Walking/Walk_Four_East.bmp"} };

    std::map <std::string, std::string> AssetsActions = { { "SpaceMan_Standing", "Assets/SpaceMan_PNG/SpaceMan_East/SpaceMan_Standing.bmp"},{ "SpaceMan_Shooting", "Assets/SpaceMan_PNG/SpaceMan_East/SpaceMan_shooting.bmp"} };
    
    GraphicsComponent* graphicsSpaceMan = new GraphicsComponent(AssetsWalk,AssetsActions, windowTemp, renderTemp);
    MovementComponent* movementSpaceMan = new MovementComponent();
    GameObject* SpaceMan = new GameObject(graphicsSpaceMan,movementSpaceMan);


    while (true)
    {
        SpaceMan->update();
    }
    
}





