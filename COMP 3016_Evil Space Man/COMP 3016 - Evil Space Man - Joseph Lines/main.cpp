#include "GameObject.h"
#include "SDL3/SDL.h"
#include <iostream>;


int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("EvilSpaceMan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,0);

    //Creating a character system
    GameObject* gameOne = new GameObject();

    gameOne->InputValues(new Physics());
}





