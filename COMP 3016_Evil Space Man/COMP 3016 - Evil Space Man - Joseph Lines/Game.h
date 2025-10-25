#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
class Game
{
	//Game Methods
public:
	//SDL window initalize function does not support std libary, therefore had to use char*
	Game(const char* windowName,int width, int height, SDL_WindowFlags flags);
	SDL_Renderer* getRenderer() { return renderWindow; }
	
	//Could update our components here
	void UpdateGame();


	void Destory_Window();

	void RenderFont(std::wstring textInput, TTF_Font* newStyle);
	
protected:
	//When declared, not pointing to any valid memory
	SDL_Window* newWindow;
	SDL_Renderer* renderWindow;
	SDL_Texture* combinedTexture;
	SDL_FRect* rect;
};