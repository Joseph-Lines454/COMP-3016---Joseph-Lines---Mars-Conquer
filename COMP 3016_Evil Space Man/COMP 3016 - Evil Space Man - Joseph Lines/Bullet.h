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
	int xPos = 0;
	int yPos = 0;
	//TargetRect
public:
	
	Bullet(SDL_Renderer* renderBullIn, const char* AssetName);
	// Get the bullet moving
	bool MoveBulletUpdate(SDL_FRect* Target, Health* other, bool crouth, bool alreadyHit);
	SDL_FRect* ViewBulletGet();
	
	void SetNewPos(float xPos, float yPos);
};
