#include "GameObject.h"
#include "SDL3/SDL.h"
#include <iostream>;
#include "Game.h"
#include "MainMenu.h"
#include <SDL3_ttf/SDL_ttf.h>
#include "Instructions.h"
#include "AlienMov.h"
#include "AlienGameObject.h"
#include <map>
int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

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

    SDL_Renderer* renderTemp = gameNew->GetRenderWindow();
    SDL_Window* renderWindow = gameNew->GetWindow();
    delete gameNew;
    Instructions* Instruction = new Instructions();
    Instruction->InstructionText(renderTemp);
    Instruction->UpdateGame();


    // SPACEMAN DEFINITION

    std::map <std::string, std::string> AssetsWalkEast = {{"Walking_One","Assets/SpaceMan_PNG/SpaceMan_East/Walking/Walk_One_East.bmp"},{"Walking_Two","Assets/SpaceMan_PNG/SpaceMan_East/Walking/Walk_Two_East.bmp"}
    ,{"Walking_Three","Assets/SpaceMan_PNG/SpaceMan_East/Walking/Walk_Three_East.bmp"},{"Walking_Four","Assets/SpaceMan_PNG/SpaceMan_East/Walking/Walk_Four_East.bmp"} };
    std::map <std::string, std::string> AssetsActionsEast = { { "SpaceMan_Standing", "Assets/SpaceMan_PNG/SpaceMan_East/SpaceMan_Standing.bmp"},{ "SpaceMan_Shooting", "Assets/SpaceMan_PNG/SpaceMan_East/SpaceMan_shooting.bmp"},{ "SpaceMan_punch", "Assets/SpaceMan_PNG/SpaceMan_East/SpaceMan_punch.bmp"},{ "SpaceMan_Kicking", "Assets/SpaceMan_PNG/SpaceMan_East/SpaceMan_Kicking.bmp"},{ "SpaceMan_fighting_stance", "Assets/SpaceMan_PNG/SpaceMan_East/SpaceMan_fighting_stance.bmp"},{ "SpaceMan_Croutching", "Assets/SpaceMan_PNG/SpaceMan_East/SpaceMan_Croutching.bmp"} };

    GraphicsComponent* graphicsSpaceMan = new GraphicsComponent(AssetsWalkEast,AssetsActionsEast, renderTemp);
    MovementComponent* movementSpaceMan = new MovementComponent(650);
    Health* healthSpaceMan = new Health();
    GameObject* SpaceMan = new GameObject(graphicsSpaceMan,movementSpaceMan, healthSpaceMan);

    //END OF SPACEMAN DEFINITION

  

    
    std::map <std::string, std::string> AssetsWalkEastAlien = { {"Walking_One","Assets/AlienOne_PNG/Alien_One_West/Walking/Walk_One.bmp"},{"Walking_Two","Assets/AlienOne_PNG/Alien_One_West/Walking/Walk_Two.bmp"}
    ,{"Walking_Three","Assets/AlienOne_PNG/Alien_One_West/Walking/Walk_Three.bmp"},{"Walking_Four","Assets/AlienOne_PNG/Alien_One_West/Walking/Walk_Four.bmp"} };
    std::map <std::string, std::string> AssetsActionsEastAlien = { { "SpaceMan_Standing", "Assets/AlienOne_PNG/Alien_One_West/Alien_Stand.bmp"},{ "SpaceMan_Shooting", "Assets/AlienOne_PNG/Alien_One_West/AlienShoot.bmp"},{ "SpaceMan_punch", "Assets/AlienOne_PNG/Alien_One_West/Alien_Punch.bmp"},{ "SpaceMan_Kicking", "Assets/AlienOne_PNG/Alien_One_West/Alien_Kick.png"},{ "SpaceMan_fighting_stance", "Assets/AlienOne_PNG/Alien_One_West/Alien_Fighting_Stance.bmp"},{ "SpaceMan_Croutching", "Assets/AlienOne_PNG/Alien_One_West/Alien_Crouth.bmp"} };

    //Figure out how to implement different controls
    
    GraphicsComponent* graphicsAlien = new GraphicsComponent(AssetsWalkEastAlien, AssetsActionsEastAlien, renderTemp);
    AlienMov* movementAlien = new AlienMov(100);
    Health* healthAlien = new Health();
    AlienGameObject* Alien = new AlienGameObject(graphicsAlien, movementAlien, healthAlien);


    //Level 1
    const int FPS = 60;
    const int Delay = 1000 / FPS;
    //First GameLoop

    while (true)
    {
        Uint64 start = SDL_GetTicks();
        Uint64 duration;
        SDL_RenderClear(renderTemp);
        
        SDL_Surface* bmp = SDL_LoadBMP("Assets/Backgrounds/Mars_Menu_Background.bmp");
        SDL_Texture* textureBackground = SDL_CreateTextureFromSurface(renderTemp, bmp);
        SDL_RenderTexture(renderTemp, textureBackground, NULL, NULL);
        
        Alien->update(renderTemp);
        SpaceMan->update(renderTemp);
        SDL_RenderPresent(renderTemp);
        Uint64 frameDuration = SDL_GetTicks() - start;

        if (Delay > frameDuration)
        {
            SDL_Delay(Delay - frameDuration);
        }
        

    }


    //We need to get all of the positions of the rectangle
    
}





