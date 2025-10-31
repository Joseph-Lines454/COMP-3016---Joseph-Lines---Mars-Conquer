#pragma once
#include <map>
#include <iostream>
#include "SDL3/SDL.h"
#include <map>
class GraphicsComponent {
public:
	//Get the images inputted here

	

	GraphicsComponent(std::map <std::string, std::string> RenderWalkingEast, std::map <std::string, std::string> RenderActionsEast, SDL_Renderer* rendererPass);
	//we should start with idle first
	
	void RenderUpdate(std::string movementType, SDL_FRect* rectagleUp, SDL_Renderer* renderIn);
	
	SDL_Texture* GetTexureExt();
private:
	void SetRectangle(SDL_FRect* rectangleIn);
	std::map <std::string, SDL_Texture*> EastActions;
	std::map <std::string, SDL_Texture*> EastWalk;
	SDL_Texture* GetTexture(std::string surfaceTag, std::map <std::string, SDL_Texture*>& TextureGet);
	void TextureCreation(std::map <std::string, std::string> surfaceCreation, std::map <std::string, SDL_Texture*>& surfaceMap);
	// This is needed for when we render to the screen
	SDL_Window* newWindow;
	SDL_Renderer* renderWindow;
	SDL_FRect* Rectangle;
	int EastWalkingIndex = -1;
	SDL_Texture* TextureRender;
	
};
