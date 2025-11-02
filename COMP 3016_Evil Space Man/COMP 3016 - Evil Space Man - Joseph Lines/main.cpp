#include "GameObject.h"
#include "SDL3/SDL.h"
#include <iostream>;
#include "Game.h"
#include "MainMenu.h"
#include <SDL3_ttf/SDL_ttf.h>
#include "Instructions.h"
#include "Health.h"
#include "AlienGameObject.h"
#include "AlienMov.h"
#include "Bullet.h"
#include "EndScreen.h"
#include <chrono>

#include <map>
int main(int argc, char* argv[])
{



    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    int windowWidth = 800;
    int windowHeight = 800;
    std::wstring title = L"Evil SpaceMan";
    MainMenu* gameNew = new MainMenu("EvilSpaceMan", windowWidth, windowHeight, 0);
    
    gameNew->SetTitleText("Evil SpaceMan", 8, 2);
    gameNew->SetPressPlay("Click Any Key", 1, 1);

    //Current Game loop
    gameNew->UpdateGame();
    while (true)
    {
        
        if (gameNew->PlayButtonCheck())
        {
            //Some code that transports the user into the game - Let the user change window
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
    Health* healthSpaceMan = new Health(100);
    GameObject* SpaceMan = new GameObject(graphicsSpaceMan,movementSpaceMan, healthSpaceMan);

    //END OF SPACEMAN DEFINITION

  

    
    std::map <std::string, std::string> AssetsWalkEastAlien = { {"Walking_One","Assets/AlienOne_PNG/Alien_One_West/Walking/Walk_One.bmp"},{"Walking_Two","Assets/AlienOne_PNG/Alien_One_West/Walking/Walk_Two.bmp"}
    ,{"Walking_Three","Assets/AlienOne_PNG/Alien_One_West/Walking/Walk_Three.bmp"},{"Walking_Four","Assets/AlienOne_PNG/Alien_One_West/Walking/Walk_Four.bmp"} };
    std::map <std::string, std::string> AssetsActionsEastAlien = { { "SpaceMan_Standing", "Assets/AlienOne_PNG/Alien_One_West/Alien_Stand.bmp"},{ "SpaceMan_Shooting", "Assets/AlienOne_PNG/Alien_One_West/AlienShoot.bmp"},{ "SpaceMan_punch", "Assets/AlienOne_PNG/Alien_One_West/Alien_Punch.bmp"},{ "SpaceMan_Kicking", "Assets/AlienOne_PNG/Alien_One_West/Alien_Kick.bmp"},{ "SpaceMan_fighting_stance", "Assets/AlienOne_PNG/Alien_One_West/Alien_Fighting_Stance.bmp"},{ "SpaceMan_Croutching", "Assets/AlienOne_PNG/Alien_One_West/Alien_Crouth.bmp"} };

    //Figure out how to implement different controls
    //Bullet* bullet = new Bullet(movementAlien->GetRectangle()->x, movementAlien->GetRectangle()->y, renderTemp, "Assets/Bullets/lemon.bmp");
    Bullet* bullet = new Bullet(renderTemp, "Assets/Bullets/apple.bmp");;
    GraphicsComponent* graphicsAlien = new GraphicsComponent(AssetsWalkEastAlien, AssetsActionsEastAlien, renderTemp);
    AlienMov* movementAlien = new AlienMov(600, 600, bullet, 400000);
    Health* healthAlien = new Health(100);
    AlienGameObject* Alien = new AlienGameObject(graphicsAlien, movementAlien, healthAlien);

    //Level 1
    const int FPS = 60;
    const int Delay = 1000 / FPS;
    

    std::vector<std::string> rounds = {"Round One", "Round Two", "Round Three"};
  

    

    auto startTimer = std::chrono::steady_clock::now();

    //First GameLoop
    for (int i = 0; i < 3; i++)
    {
        SDL_RenderClear(renderTemp);
        Game* playScreen = new Game();
        SDL_FRect* setPos = new SDL_FRect{ 200.0f,200.0f,200.0f,200.0f };
        SDL_Texture* newtext = SDL_CreateTextureFromSurface(renderTemp, playScreen->RenderFont(rounds[i]));

        SDL_Surface* bmp = SDL_LoadBMP("Assets/Backgrounds/Mars_Menu_Background.bmp");
        SDL_Texture* textureBackground = SDL_CreateTextureFromSurface(renderTemp, bmp);


        SDL_RenderTexture(renderTemp, textureBackground, NULL, NULL);
        SDL_RenderTexture(renderTemp, newtext, NULL, setPos);
        SDL_RenderPresent(renderTemp);
        SDL_Delay(5000);



        while (true)
        {
            Uint64 start = SDL_GetTicks();
            Uint64 duration;
            SDL_RenderClear(renderTemp);

            SDL_Surface* bmp = SDL_LoadBMP("Assets/Backgrounds/Mars_Menu_Background.bmp");
            SDL_Texture* textureBackground = SDL_CreateTextureFromSurface(renderTemp, bmp);
            SDL_RenderTexture(renderTemp, textureBackground, NULL, NULL);

            Alien->Update(renderTemp, movementSpaceMan->GetRectangle(), healthSpaceMan, movementSpaceMan->GetCrouth());
            SpaceMan->update(renderTemp, movementAlien->GetRectangle(), healthAlien);
            if (movementAlien->GetGameOver() == true)
            {
                break;
            }
            SDL_RenderPresent(renderTemp);
            Uint64 frameDuration = SDL_GetTicks() - start;

            if (Delay > frameDuration)
            {
                SDL_Delay(Delay - frameDuration);
            }
            
            
        }

        if (healthSpaceMan->GetHealth() <= 0)
        {
            //Take player to looser screen
            EndScreen* end = new EndScreen();

           

            SDL_RenderClear(renderTemp);

            SDL_Surface* bmp = SDL_LoadBMP("Assets/Backgrounds/Mars_Menu_Background.bmp");
            SDL_Texture* textureBackground = SDL_CreateTextureFromSurface(renderTemp, bmp);

            SDL_FRect* DisplayFinalScore = new SDL_FRect{ 200.0f,600.0f,200.0f,200.0f };
            SDL_Texture* newtext = SDL_CreateTextureFromSurface(renderTemp, end->RenderFont("You Lose!"));
            SDL_RenderTexture(renderTemp, textureBackground, NULL, NULL);
            SDL_RenderTexture(renderTemp, newtext, NULL, DisplayFinalScore);
            SDL_RenderPresent(renderTemp);
            SDL_Delay(10000);

           
            i = 2;
            break;
        }
       
        healthSpaceMan->ResetHealth(100);
        healthAlien->ResetHealth(100);
        movementAlien->SetGameOver(false);
        movementSpaceMan->UpdateRectangle(100, 600);
        movementAlien->Reset(600, 600);
        
        
    }
    auto endclock = std::chrono::steady_clock::now();

    if (healthSpaceMan->GetHealth() > 0)
    {
        EndScreen* end = new EndScreen();

        std::chrono::nanoseconds difference = endclock - startTimer;
        std::chrono::duration secondsDuration = std::chrono::duration_cast<std::chrono::seconds>(difference);

        SDL_RenderClear(renderTemp);

        SDL_Surface* bmp = SDL_LoadBMP("Assets/Backgrounds/Mars_Menu_Background.bmp");
        SDL_Texture* textureBackground = SDL_CreateTextureFromSurface(renderTemp, bmp);




        SDL_FRect* DisplayFinalScore = new SDL_FRect{ 200.0f,400.0f,600.0f,200.0f };
        SDL_Texture* newtext = SDL_CreateTextureFromSurface(renderTemp, end->RenderFont(end->ReadFromFile(secondsDuration)));
        SDL_RenderTexture(renderTemp, textureBackground, NULL, NULL);
        SDL_RenderTexture(renderTemp, newtext, NULL, DisplayFinalScore);
        SDL_RenderPresent(renderTemp);
        SDL_Delay(10000);

        std::cout << "End of Game" << std::endl;
    }
    
}





