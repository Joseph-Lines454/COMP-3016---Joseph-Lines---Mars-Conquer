#pragma once
#include "Bullet.h"
#include <iostream>
//Bullet Constructor


Bullet::Bullet(int xPos, int Ypos, SDL_Renderer* renderBullIn, const char* AssetName)
{
	this->xPos = xPos;
	this->yPos = yPos;
	ViewBullet = new SDL_FRect{ static_cast<float>(yPos),static_cast<float>(xPos),50.0f,50.0f};
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
	SDL_RenderTexture(renderIn, BulletText, NULL, ViewBullet);
}
SDL_FRect* ViewBulletGet()
{
	return ViewBulletGet();
}


void  Bullet::MoveBulletUpdate(SDL_FRect* Target, Health* other) {
	//Because the Alien is using it, shoot at the player
	ViewBullet->x = xPos--;
	SDL_RenderTexture(renderIn, BulletText, NULL, ViewBullet);
	//Render Bullet here

	if (ViewBullet->x == Target->x)
	{
		//some code here that takes health of other player
	}
	else if (ViewBullet->x == 0)
	{
		//some code here that destroys bullet and Resets for next use

	}
	
	std::cout << "SHOULD BE RENDERING!! " << std::endl;
	if (BulletText == NULL)
	{
		std::cout << "Texture issue!" << std::endl;
	}


	
	

}



