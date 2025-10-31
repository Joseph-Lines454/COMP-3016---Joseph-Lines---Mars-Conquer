#pragma once

#include <map>
#include <iostream>
#include "SDL3/SDL.h"
#include "Health.h"


class AlienMov {
public:
	//Get the images inputted here

	// Some shit herelol!

	std::string Update(SDL_FRect* other, int health, Health* otherhealth);
	SDL_FRect* GetRectangle();
	//Some methods here are needed to render the image correctly
	AlienMov(int XstartPos);




private:
	//coordinates for the window - we will check once we collide with the world componenet
	int currentposX = 0;
	int currentPosY = 0;
	SDL_Window* newWindow;
	SDL_Renderer* renderWindow;
	SDL_FRect* recttangleMove;

};