#pragma once
#include "Bullet.h"
#include <iostream>
//Bullet Constructor


Bullet::Bullet(SDL_Renderer* renderBullIn, const char* AssetName)
{
	this->xPos = xPos;
	this->yPos = yPos;
	//ViewBullet = new SDL_FRect{ static_cast<float>(yPos),static_cast<float>(xPos),50.0f,50.0f};
	SDL_Surface* surfaceTemp = SDL_LoadBMP(AssetName);
	SDL_Texture* TextTemp = SDL_CreateTextureFromSurface(renderBullIn, surfaceTemp);
	renderIn = renderBullIn;
	if (renderBullIn == NULL)
	{
		std::cout << "RENDER FAILED" << std::endl;
	}

	if (surfaceTemp == NULL)
	{
		std::cout << "Failed to load asset!" << std::endl;
	}
	else if (TextTemp == NULL)
	{
		std::cout << "Failed to create texure" << std::endl;
	}

	BulletText = TextTemp;
	
}


void Bullet::SetNewPos(float xPos, float yPos) {
	
	ViewBullet = new SDL_FRect(xPos,yPos,50.0f,50.0f);
	
	this->xPos = xPos;
	this->xPos = yPos;
};

bool Bullet::MoveBulletUpdate(SDL_FRect* Target, Health* other) {
	//Because the Alien is using it, shoot at the player

	ViewBullet->x = ViewBullet->x - 4;
	

	//Render Bullet here

	if (ViewBullet->x >= 10)
	{
		//some code here that destroys bullet and Resets for next use
		SDL_RenderTexture(renderIn, BulletText, NULL, ViewBullet);
	}
	if (ViewBullet->x == Target->x)
	{
		other->SetHealth(100);
		std::cout << "Hit!" << std::endl;
		return true;
		//some code here that takes health of other playercccccccccc
	}
	
	
	

	return false;
	

}



