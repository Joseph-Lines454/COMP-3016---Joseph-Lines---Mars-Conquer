#pragma once
#include "Game.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>

class MainMenu : Game
{
public:
	//Inheriting the Game Constructor
	using Game::Game;

	//Could update our components here
	void UpdateGame();

	void Create_Window();
	void Destory_Window();

	//Using the inherited destroy constructor properties
private:
	
};