#pragma once
#include <iostream>
#include "Game.h"
#include <vector>
#include "MainMenu.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_ttf/SDL_ttf.h>

class Instructions : Game {
public:



	void InstructionText(SDL_Renderer* renderTemp);
	std::vector<SDL_FRect*> GetViewText();
	std::vector<SDL_Texture*> GetTextures();
	void UpdateGame() override;
private:
	//define this so we can go 
	std::vector<SDL_FRect*> viewText;
	std::vector<SDL_Texture*> combinedTextureTitle;
};