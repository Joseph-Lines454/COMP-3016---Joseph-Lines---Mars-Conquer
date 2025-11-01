#pragma once

#include <map>
#include <iostream>
#include "SDL3/SDL.h"
#include "Health.h"
#include <stdint.h>
#include "Bullet.h"

class AlienMov {
public:
	//Get the images inputted here

	// Some shit herelol!

	std::string Update(SDL_FRect* other, int health, Health* otherhealth, bool Crouth);
	SDL_FRect* GetRectangle();
	//Some methods here are needed to render the image correctly
	AlienMov(int XstartPos,int windowWidth, Bullet* BulletIn);
	bool GetGameOver();
private:
	//coordinates for the window - we will check once we collide with the world componenet
	int currentposX = 0;
	int currentPosY = 0;
	SDL_Window* newWindow;
	SDL_Renderer* renderWindow;
	SDL_FRect* recttangleMove;
	Uint64 maxTimeSlow = 10000;
	Uint64 currentTimeSlow = 0;
	Uint64 maxHit = 100000;
	Uint64 currentHit = 0;
	std::string last = "";
	int randomNum = 0;
	int windowWidth;
	bool GameOver = false;
	bool newPos = false;
	Bullet* BulletAlien;
};