#include <vector>
#include <iostream>
#include "GraphicsComponent.h"
#include "SDL3/SDL.h"
#include <map>
GraphicsComponent::GraphicsComponent(std::map <std::string, std::string> AssetPaths, SDL_Window* windowPass, SDL_Renderer* rendererPass) {
	//We need to make the relative paths into SDL_Rect Objects

	//Assign the passed window functions to the class Render Functions
	newWindow = windowPass;
	renderWindow = rendererPass;

	
	for (auto i = AssetPaths.begin(); i != AssetPaths.end(); i++)
	{
		//Makes the asset path into a SDL surface, then it is passed into the assets.
		
		//converting string to char* for surface
		SDL_Surface* surfaceTemp = SDL_LoadBMP(i->second.c_str());
		Assets.insert({ i->first,surfaceTemp });
	}

};

void GraphicsComponent::UpdateImage(std::string Action,int posX, int PosY) {
	
	

};


SDL_Surface* GraphicsComponent::GetSurface(std::string surfaceFind)
{
	for (auto i = Assets.begin(); i != Assets.end(); i++)
	{
		//Makes the asset path into a SDL surface, then it is passed into the assets.

		std::string temp = i->first;


		//Seperate functionality for walking

		//Makes the asset path into a SDL surface, then it is passed into the assets.
		if (temp.find(surfaceFind))
		{
			//Send the user to the appropriate method
			return i->second;
		}
	}
}





void GraphicsComponent::RenderImage(int posX, int posY) {
	SDL_RenderClear(renderWindow);

	//We are going to have to get the Position RenderCors


	//This is the size and where it will be rendered



	// This will get the standing surface to start of with, with the character
	SDL_Texture* RenderAnimation = SDL_CreateTextureFromSurface(renderWindow, GetSurface("SpaceMan_Standing"));

	SDL_FRect* rectTemp = new SDL_FRect{ 0,0,static_cast<float>(posX),static_cast<float>(posY)};



	SDL_RenderTexture(renderWindow, RenderAnimation, NULL, rectTemp);


	
	SDL_RenderPresent(renderWindow);
	


};


void GraphicsComponent::WalkingAnimation()
{
	//depending on where the character currently is
}
