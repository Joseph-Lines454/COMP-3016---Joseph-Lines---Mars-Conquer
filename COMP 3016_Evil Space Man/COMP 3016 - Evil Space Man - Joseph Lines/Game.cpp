#include "Game.h"
#include <iostream>
#include <SDL3/SDL.h>
// Methods have been declared in the header file, Methods are being decleared here

Game::Game(const char* windowName, int width, int height, SDL_WindowFlags flags){ 
	try
	{
		newWindow = SDL_CreateWindow(windowName, width, height, flags);
		renderWindow = SDL_CreateRenderer(newWindow, NULL);
	}
	catch(SDL_Window* windowExcept)
	{
		std::cout << "Somthing went wrong with the window intialization!" << std::endl;
	}
	catch (SDL_Renderer* renderer)
	{
		std::cout << "Somthing when wrong with the renderer initalization!" << std::endl;
	}
};





void Game::UpdateGame()
{

}


