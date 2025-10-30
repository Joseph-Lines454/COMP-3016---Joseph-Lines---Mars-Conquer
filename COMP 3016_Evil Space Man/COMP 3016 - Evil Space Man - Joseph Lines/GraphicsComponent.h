#pragma once
#include <map>
#include <iostream>
#include "SDL3/SDL.h"
#include <map>
class GraphicsComponent {
public:
	//Get the images inputted here

	

	GraphicsComponent(std::map <std::string, std::string> RenderWalkingEast, std::map <std::string, std::string> RenderActionsEast, SDL_Window* windowPass, SDL_Renderer* rendererPass);
	

	//Some methods here are needed to render the image correctly

	void TextureCreation(std::map <std::string, std::string> surfaceCreation, std::map <std::string, SDL_Texture*>& surfaceMap);
	//we should start with idle first
	
	void RenderInital();
	SDL_Texture* GetTexture(std::string surfaceTag, std::map <std::string, SDL_Texture*>& TextureGet);
	void RenderUpdate(std::string movementType);

private:
	//
	std::map <std::string, SDL_Texture*> EastActions;
	std::map <std::string, SDL_Texture*> EastWalk;

	// This is needed for when we render to the screen
	SDL_Window* newWindow;
	SDL_Renderer* renderWindow;
	SDL_FRect* Rectangle;
	int EastWalkingIndex = -1;

};
