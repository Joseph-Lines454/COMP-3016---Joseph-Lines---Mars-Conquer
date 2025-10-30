#include <iostream>
#include "MovementComponent.h"
#include <SDL3/SDL.h>


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
			
				return "SpaceMan_Walking_East";
			}
			else if (event.key.scancode == SDL_SCANCODE_A)
			{
				std::cout << "The player is moving right!" << std::endl;
				
				return "walking_west";
			}
			else if (event.key.scancode == SDL_SCANCODE_F)
			{
				return "SpaceMan_Shooting";
			}
			
		}
		if (event.type == SDL_EVENT_KEY_UP)
		{

			return "SpaceMan_Standing";

		}
		

		
	}


	//This has to be done per frame

	return "";
	

	//CheckCollision();

};


void MovementComponent::CheckCollision(SDL_FRect* Viewing)
{

	//Need to check if the rectangle is within this area
	//This wont be correct, will deal with this later


	if (SDL_GetWindowSurface(newWindow)->h <= Viewing->y && Viewing->y <= 0) {
	
		std::cout << "Probs Make this a return statement because" << std::endl;
	}
	else if (SDL_GetWindowSurface(newWindow)->w <= Viewing->x && Viewing->x <= 0) {

		std::cout << "To Far X Aixs " << std::endl;
	}

	//Another some 

}

