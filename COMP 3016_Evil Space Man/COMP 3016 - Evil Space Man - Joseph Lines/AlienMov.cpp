#pragma once
#include <map>
#include <iostream>
#include "Health.h"
#include "SDL3/SDL.h"
#include "GameObject.h"
#include "AlienMov.h"
#include <cstdlib>

AlienMov::AlienMov(int XstartPos)
{
	int windowWidth, windowHeight = 0;

	std::cout << windowHeight << std::endl;
	recttangleMove = new SDL_FRect{ static_cast<float>(XstartPos),800 - 150,150.0f,150.0f };
	currentposX = XstartPos;
}

//Need to compare with other object
std::string AlienMov::Update(SDL_FRect* other, int health, Health* otherhealth)
{
	//some code that detects if window has been hit


	//need to check the health of the Alien
	
	

	if (recttangleMove->x != other->x && recttangleMove->x >= other->x)
	{



		currentposX = currentposX - 5;
		recttangleMove->x = currentposX;
		return "SpaceMan_Walking_East";
	}

	

	

	int randomNum = rand() % 4;
	if ((recttangleMove->x < other->x + 10 || recttangleMove->x > other->x - 10))
	{

		if (randomNum == 1)
		{
			otherhealth->SetHealth(otherhealth->GetHealth() - 20);
			return "SpaceMan_Kicking";
		}
		else if (randomNum == 2)
		{
			otherhealth->SetHealth(otherhealth->GetHealth() - 10);
			return "SpaceMan_Punch";
		}
		else if (randomNum == 3)
		{
			//Shoot a bullet?
			otherhealth->SetHealth(otherhealth->GetHealth() - 50);
			return "SpaceMan_Punch";
		}

		//some random hitting components here
		std::cout << "Random selection of hitting components" << std::endl;
	}

	
	

	//Allow some actions


	return "SpaceMan_Standing";
	
};




SDL_FRect* AlienMov::GetRectangle()
{
	return recttangleMove;
}