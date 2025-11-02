#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_events.h>
class Game
{
	//Game Methods
public:
	//SDL window initalize function does not support std libary, therefore had to use char*
	Game(const char* windowName,int width, int height, SDL_WindowFlags flags);
	Game() = default;
	SDL_Renderer* getRenderer() { return renderWindow; }
	
	//Could update our components here
	virtual void UpdateGame();
	
	virtual SDL_Window* GetWindow();
	virtual SDL_Renderer* GetRenderWindow();
	virtual SDL_Surface* RenderFont(std::string textInput);
protected:
	//When declared, not pointing to any valid memory
	

	SDL_Window* newWindow;
	SDL_Renderer* renderWindow;
	SDL_Texture* combinedTextureTitle;
	SDL_FRect* rectTitle;
	int windowWidth;
	int windowHeight;
	std::wstring title;
	TTF_Font* newFont = TTF_OpenFont("Assets/Fonts/Micro5-Regular.ttf", 80);
};