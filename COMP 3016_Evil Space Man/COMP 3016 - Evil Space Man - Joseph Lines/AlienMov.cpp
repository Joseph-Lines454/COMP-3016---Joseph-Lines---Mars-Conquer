#pragma once
#include <map>
#include <iostream>
#include "Health.h"
#include "SDL3/SDL.h"
#include "GameObject.h"
#include "AlienMov.h"
#include <cstdlib>

#include "Bullet.h"

bool AlienMov::GetGameOver()
{
	return GameOver;
}

AlienMov::AlienMov(int XstartPos, int windowWidth, Bullet* BulletIn)
{
	BulletAlien = BulletIn;
	recttangleMove = new SDL_FRect{ static_cast<float>(XstartPos),800 - 200,200.0f,200.0f };
	currentposX = XstartPos;
	this->windowWidth = windowWidth;
	
}

//Need to compare with other object
std::string AlienMov::Update(SDL_FRect* other, int health, Health* otherhealth, bool Crouth)
{

	if (health <= 0 || otherhealth->GetHealth() <= 0)
	{
		std::cout << "Health: " << health << std::endl;
		std::cout << "OtherHealth: " << otherhealth->GetHealth() << std::endl;
		GameOver = true;
	}
	

	

	//Slowing down the enemy alien
	currentTimeSlow =currentTimeSlow + SDL_GetTicks();
	currentHit = currentHit + SDL_GetTicks();

	if (currentHit >= maxHit)
	{
		randomNum = rand() % 5;
		
	}

	if (currentTimeSlow >= maxTimeSlow)
	{
		// need to check 
		if (recttangleMove->x != other->x + 20 && recttangleMove->x >= other->x + 20 && health >= 40 && (recttangleMove->x) != 0)
		{
			currentTimeSlow = 0;


			currentposX = currentposX - 5;
			recttangleMove->x = currentposX;
			
			return "SpaceMan_Walking_East";
		}
		if (health < 40 && recttangleMove->x != windowWidth)
		{
			currentTimeSlow = 0;

			
			currentposX = currentposX + 5;
			recttangleMove->x = currentposX;

			return "SpaceMan_Walking_East";
		}
		if (health < 40 && recttangleMove->x == windowWidth && newPos == false)
		{
			BulletAlien->SetNewPos(recttangleMove->x,recttangleMove->y);
			newPos = true;
		}
		if (health < 40 && recttangleMove->x == windowWidth)
		{
			last = "";
			std::cout << Crouth << std::endl;
			if (BulletAlien->MoveBulletUpdate(other, otherhealth) == true && Crouth == false) {
				GameOver = true;
			}
		}

		if (recttangleMove->x == other->x + 20 && currentHit >= maxHit)
		{
			currentHit = 0;
			std::cout << "OtherHealth: " << otherhealth->GetHealth() << std::endl;
			if (randomNum == 1)
			{
				otherhealth->SetHealth(2);
				
				last = "SpaceMan_Kicking";
				return "SpaceMan_Kicking";
			}
			else if (randomNum == 2)
			{
				otherhealth->SetHealth(5);
				last = "SpaceMan_punch";
				return "SpaceMan_punch";
			}
			else if (randomNum == 3)
			{
				//Shoot a bullet?
				otherhealth->SetHealth(2);
				last = "SpaceMan_punch";
				return "SpaceMan_punch";
			}
			else
			{
				last = "SpaceMan_Standing";
				return "SpaceMan_Standing";
			}
			
			//some random hitting components here
			
			
		}
		
		currentTimeSlow = 0;
	}
	
	return last;
	
};




SDL_FRect* AlienMov::GetRectangle()
{
	return recttangleMove;
}