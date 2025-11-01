#pragma once
#include "Game.h"
#include <iostream>
#include <fstream>

class EndScreen : Game
{
public:
	void ReadFromFile();

	//virtual SDL_Surface* RenderFont(std::wstring textInput);
};