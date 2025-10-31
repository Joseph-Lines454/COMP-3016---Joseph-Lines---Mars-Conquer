#pragma once
#include <vector>
#include <iostream>
#include "GraphicsComponent.h"
#include "SDL3/SDL.h"
#include <map>
GraphicsComponent::GraphicsComponent(std::map <std::string, std::string> RenderWalkingEast, std::map <std::string, std::string> RenderActionsEast, SDL_Renderer* rendererPass) {
	//We need to make the relative paths into SDL_Rect Objects

	//Assign the passed window functions to the class Render Functions

	renderWindow = rendererPass;
	int windowWidth, windowHeight;

	//Define all of the walk comonents
	TextureCreation(RenderWalkingEast, EastWalk);
	TextureCreation(RenderActionsEast, EastActions);
};

//Create Surfaces

void GraphicsComponent::TextureCreation(std::map <std::string, std::string> surfaceCreation, std::map <std::string, SDL_Texture*>& surfaceMap)
{
	for (auto i = surfaceCreation.begin(); i != surfaceCreation.end(); i++)
	{
		//Makes the asset path into a SDL surface, then it is passed into the assets.

		//converting string to char* for surface
		SDL_Surface* surfaceTemp = SDL_LoadBMP(i->second.c_str());
		SDL_Texture* TextTemp = SDL_CreateTextureFromSurface(renderWindow,surfaceTemp);


		if (!surfaceTemp)
		{
			std::cout << "Error here!" << std::endl;
			std::cout << i->first << std::endl;
		}
		else
		{
			std::cout << "No Error here!" << std::endl;
			std::cout << i->first << std::endl;
		}
		if (!TextTemp)
		{
			std::cout << "Didnt Work!" << std::endl;
		}
		else
		{
			surfaceMap.insert({ i->first,TextTemp });
		}
		
	}
}

SDL_Texture* GraphicsComponent::GetTexture(std::string surfaceTag, std::map <std::string, SDL_Texture*>& TextureGet){

	for (auto i = TextureGet.begin(); i != TextureGet.end(); i++)
	{
		if (i->first == surfaceTag)
		{
			return i->second;
		}
	}
}

void GraphicsComponent::SetRectangle(SDL_FRect* rectangleIn)
{
	Rectangle = rectangleIn;
}

SDL_Texture* GraphicsComponent::GetTexureExt()
{
	return TextureRender;
}

void GraphicsComponent::RenderUpdate(std::string movementType, SDL_FRect* rectagleUp, SDL_Renderer* renderIn)
{
	if (movementType != "")
	{
		SetRectangle(rectagleUp);
	}

	
	SDL_Texture* TextTemp = nullptr;
	//SDL_RenderClear(renderWindow);

	if (movementType == "SpaceMan_Walking_East")
	{
		
		EastWalkingIndex = (EastWalkingIndex + 1) % 4;
		
		std::cout << EastWalkingIndex << std::endl;
		auto EastElem = EastWalk.begin();
		std::advance(EastElem, 0);
		std::advance(EastElem, EastWalkingIndex);
		
		std::cout << EastElem->first << std::endl;

		//Gets the name we need to 
		movementType = EastElem->first;
		TextTemp = GetTexture(movementType, EastWalk);
		
		
	}
	if (movementType == "SpaceMan_Walking_West")
	{
		EastWalkingIndex = EastWalkingIndex - 1;
		if (EastWalkingIndex <= -1)
		{
			EastWalkingIndex = 3;
		}
		std::cout << EastWalkingIndex << std::endl;
		

		
		auto EastElem = EastWalk.rbegin();
		//std::advance(EastElem, 0);
		std::advance(EastElem, EastWalkingIndex);

		//std::cout << EastElem->first << std::endl;

		//Gets the name we need to 
		movementType = EastElem->first;
		TextTemp = GetTexture(movementType, EastWalk);


	}
	

	if (movementType == "SpaceMan_Croutching" || movementType == "SpaceMan_Shooting" || movementType == "SpaceMan_Standing" || movementType == "SpaceMan_punch" || movementType == "SpaceMan_Kicking")
	{
		
		TextTemp = GetTexture(movementType, EastActions);
		
	}
	


	//Inital Render
	if (TextTemp != NULL)
	{
		//SDL_RenderTexture(renderWindow, TextTemp, NULL, Rectangle);
		TextureRender = TextTemp;
		
	}
	if (TextTemp == NULL && movementType != "")
	{
		std::cout << "Could not see the graphic!" << std::endl;
	}
	
	//SDL_RenderPresent(renderWindow);
	SDL_RenderTexture(renderIn, TextureRender, NULL, Rectangle);
}




