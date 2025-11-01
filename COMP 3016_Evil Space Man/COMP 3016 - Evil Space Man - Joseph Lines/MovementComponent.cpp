#pragma once
#include <iostream>
#include "MovementComponent.h"
#include "Health.h"
#include <SDL3/SDL.h>



MovementComponent::MovementComponent(int XstartPos)
{
	int windowWidth, windowHeight = 0;
	
	
	recttangleMove = new SDL_FRect{ static_cast<float>(XstartPos),800 - 200,200.0f,200.0f};
}
std::string MovementComponent::Update(SDL_FRect* other, int health, Health* otherhealth)
{
	
	//We want the spaceman not to be to close to the alien



	

	//Key detection - We need to limit this to every frame otherwise the character will move to quickly

		
	SDL_Event event;
	//Check null
	while (SDL_PollEvent(&event)) {

		std::cout << otherhealth->GetHealth() << std::endl;
		

		//This is where to detect Movement of the spaceman
		if (event.type == SDL_EVENT_KEY_DOWN)
		{

			//Now we have to update the position of the rectangle
			if (event.key.scancode == SDL_SCANCODE_D && recttangleMove->x < other->x)
			{
				//std::cout << "The player is moving left!" << std::endl;
				currentposX = currentposX + 10;
				return "SpaceMan_Walking_East";
			}
			else if (event.key.scancode == SDL_SCANCODE_A && recttangleMove->x > 0)
			{
				currentposX = currentposX - 10;
				//std::cout << "The player is moving right!" << std::endl;
				
				return "SpaceMan_Walking_West";
			}
			else if (event.key.scancode == SDL_SCANCODE_F)
			{
				otherhealth->SetHealth(2);
				return "SpaceMan_Shooting";
			}
			else if (event.key.scancode == SDL_SCANCODE_C)
			{
				otherhealth->SetHealth(5);
				return "SpaceMan_Croutching";
			}
			else if (event.key.scancode == SDL_SCANCODE_SPACE)
			{
				otherhealth->SetHealth(2);
				return "SpaceMan_punch";
			}
			else if (event.key.scancode == SDL_SCANCODE_R)
			{
				otherhealth->SetHealth(2);
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



