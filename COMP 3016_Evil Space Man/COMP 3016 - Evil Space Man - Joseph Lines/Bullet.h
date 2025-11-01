#pragma once
#include "SDL3/SDL.h";
#include "Health.h"
#include <iostream>
class Bullet
{

private:
	std::string bulletAsset;
	SDL_FRect* ViewBullet;
	SDL_Texture* BulletText = nullptr;
	SDL_Renderer* renderIn = nullptr;
	int xPos;
	int yPos;
	//TargetRect
public:
	
	Bullet(int xPos, int Ypos, SDL_Renderer* renderBullIn, const char* AssetName);
	// Get the bullet moving
	void MoveBulletUpdate(SDL_FRect* Target, Health* other);
	SDL_FRect* ViewBulletGet();
	

};
