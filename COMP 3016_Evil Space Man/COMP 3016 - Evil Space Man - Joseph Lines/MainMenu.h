#pragma once
#include "Game.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_ttf/SDL_ttf.h>
class MainMenu : Game
{
public:
	//Inheriting the Game Constructor
	using Game::Game;

	//Could update our components here
	void UpdateGame();

	void Create_Window();
	void Destory_Window();
	void RenderFont(std::wstring textInput, TTF_Font* newStyle, int* windowWidth, int* windowHeight);


	//Using the inherited destroy constructor properties
private:
	
};