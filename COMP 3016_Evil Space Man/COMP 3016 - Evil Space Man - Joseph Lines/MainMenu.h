#pragma once
#include "Game.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>
class MainMenu : Game
{
public:
	//Using the games constructor
	using Game::Game;

	//Could update our components here
	void UpdateGame() override;
	//SDL_Surface* RenderFont(std::wstring textInput);
	void SetTitleText(std::wstring textIn, int setXpos, int setYpos);
	void SetPressPlay(std::wstring textIn, int setXpos, int setYpos);
	bool PlayButtonCheck();
	virtual SDL_Renderer* GetRenderWindow();

private:
	std::wstring title;
	//default font that is going to be used for the title screen
	TTF_Font* newFont = TTF_OpenFont("Assets/Fonts/Micro5-Regular.ttf", 80);
	SDL_Texture* combinedTexturePressPlay;
	SDL_FRect* rectPressPlay;
};