#pragma once
#include <iostream>
#include "MovementComponent.h"
#include "Health.h"
#include <SDL3/SDL.h>

bool MovementComponent::GetCrouth()
{
	return Croutch;
}



MovementComponent::MovementComponent(int XstartPos)
{
	
	
	
	recttangleMove = new SDL_FRect{ static_cast<float>(XstartPos),800 - 200,200.0f,200.0f};
}
std::string MovementComponent::Update(SDL_FRect* other, int health, Health* otherhealth)
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		
		

		//This is where to detect Movement of the spaceman
		if (event.type == SDL_EVENT_KEY_DOWN)
		{

			//Now we have to update the position of the rectangle
			if (event.key.scancode == SDL_SCANCODE_D && recttangleMove->x < other->x)
			{
				Croutch = false;
				//std::cout << "The player is moving left!" << std::endl;
				currentposX = currentposX + 10;
				return "SpaceMan_Walking_East";
			}
			else if (event.key.scancode == SDL_SCANCODE_A && recttangleMove->x > 0)
			{
				Croutch = false;
				currentposX = currentposX - 10;
				//std::cout << "The player is moving right!" << std::endl;
				
				return "SpaceMan_Walking_West";
			}
			else if (event.key.scancode == SDL_SCANCODE_F)
			{
				Croutch = false;
				otherhealth->SetHealth(2);
				return "SpaceMan_Shooting";
			}
			else if (event.key.scancode == SDL_SCANCODE_C)
			{
				Croutch = true;
				
				return "SpaceMan_Croutching";
			}
			else if (event.key.scancode == SDL_SCANCODE_SPACE)
			{
				Croutch = false;
				otherhealth->SetHealth(2);
				return "SpaceMan_punch";
			}
			else if (event.key.scancode == SDL_SCANCODE_R)
			{
				Croutch = false;
				otherhealth->SetHealth(2);
				return "SpaceMan_Kicking";
			}
			
			
		}
		if (event.type == SDL_EVENT_KEY_UP)
		{
			Croutch = false;
			return "SpaceMan_Standing";

		}
		
	}

	recttangleMove->x = currentposX;	
	return "";
};


void MovementComponent::UpdateRectangle(int xPos,int yPos) {
	recttangleMove->x = xPos;
	recttangleMove->y = yPos;
	currentposX = xPos;
	currentPosY = yPos;
}

SDL_FRect* MovementComponent::GetRectangle()
{
	return recttangleMove;
}



