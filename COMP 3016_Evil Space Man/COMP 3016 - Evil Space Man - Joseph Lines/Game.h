#pragma once
#include <iostream>
#include <SDL3/SDL.h>
class Game
{
	//Game Methods
public:
	//SDL window initalize function does not support std libary, therefore had to use char*
	Game(char* windowName,int width, int height, SDL_WindowFlags flags,char* rendererName);

	SDL_Renderer* getRenderer() { return renderWindow; }
	
	void UpdateGame();

	


	void Destory_Window();
private:
	//When declared, not pointing to any valid memory
	SDL_Window* newWindow = nullptr;
	SDL_Renderer* renderWindow = nullptr;

	
};