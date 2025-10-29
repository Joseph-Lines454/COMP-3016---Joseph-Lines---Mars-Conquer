#pragma once
#include <map>
#include <iostream>
#include "SDL3/SDL.h"
#include <map>
class GraphicsComponent {
public:
	//Get the images inputted here

	

	GraphicsComponent(std::map <std::string, std::string> AssetPaths,SDL_Window* windowPass, SDL_Renderer* rendererPass);
	

	//Some methods here are needed to render the image correctly


	//we should start with idle first
	void RenderImage(int posX, int PosY);
	//We need to pass a key direction in here from the movement component
	SDL_Surface* GetSurface(std::string surfaceFind);

	void WalkingAnimation();
	//Pass some infomation here to about key type
	void UpdateImage(std::string Action, int posX, int PosY);


private:
	//
	std::map<std::string, SDL_Surface*> Assets;
	int CurrentIndex = 0;
	// This is needed for when we render to the screen
	SDL_Window* newWindow;
	SDL_Renderer* renderWindow;
	SDL_FRect* Rectangle;
};
