#pragma once
#include <iostream>
#include "MovementComponent.h"
#include <SDL3/SDL.h>



MovementComponent::MovementComponent(int XstartPos)
{
	int windowWidth, windowHeight = 0;
	
	std::cout << windowHeight << std::endl;
	recttangleMove = new SDL_FRect{ static_cast<float>(XstartPos),800 - 150,150.0f,150.0f};
}
std::string MovementComponent::Update()
{
	
	

	//Key detection - We need to limit this to every frame otherwise the character will move to quickly

		
	SDL_Event event;
	//Check null
	while (SDL_PollEvent(&event)) {

		//This is where to detect Movement of the spaceman
		if (event.type == SDL_EVENT_KEY_DOWN)
		{

			//Now we have to update the position of the rectangle
			if (event.key.scancode == SDL_SCANCODE_D)
			{
				std::cout << "The player is moving left!" << std::endl;
				currentposX = currentposX + 10;
				return "SpaceMan_Walking_East";
			}
			else if (event.key.scancode == SDL_SCANCODE_A)
			{
				currentposX = currentposX - 10;
				std::cout << "The player is moving right!" << std::endl;
				
				return "SpaceMan_Walking_West";
			}
			else if (event.key.scancode == SDL_SCANCODE_F)
			{
				return "SpaceMan_Shooting";
			}
			else if (event.key.scancode == SDL_SCANCODE_C)
			{
				return "SpaceMan_Croutching";
			}
			else if (event.key.scancode == SDL_SCANCODE_SPACE)
			{
				return "SpaceMan_punch";
			}
			else if (event.key.scancode == SDL_SCANCODE_R)
			{
				return "SpaceMan_Kicking";
			}
			
			
		}
		if (event.type == SDL_EVENT_KEY_UP)
		{

			return "SpaceMan_Standing";

		}
	}

	recttangleMove->x = currentposX;	
	return "";
};




SDL_FRect* MovementComponent::GetRectangle()
{
	return recttangleMove;
}



