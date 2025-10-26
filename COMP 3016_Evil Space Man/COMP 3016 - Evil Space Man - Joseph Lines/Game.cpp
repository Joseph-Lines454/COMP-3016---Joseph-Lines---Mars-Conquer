#include "Game.h"
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
// Methods have been declared in the header file, Methods are being decleared here

Game::Game(const char* windowName, int width, int height, SDL_WindowFlags flags){ 
	
	windowHeight = height;
	windowWidth = width;
	try
	{
		newWindow = SDL_CreateWindow(windowName, width, height, flags);
		renderWindow = SDL_CreateRenderer(newWindow, NULL);
	}
	catch(SDL_Window* windowExcept)
	{
		std::cout << "Somthing went wrong with the window intialization!" << std::endl;
	}
	catch (SDL_Renderer* renderer)
	{
		std::cout << "Somthing when wrong with the renderer initalization!" << std::endl;
	}
};


SDL_Renderer* Game::GetRenderWindow() {


	return renderWindow;

};


void Game::UpdateGame()
{

}



SDL_Surface* Game::RenderFont(std::wstring textInput)
{
	std::cout << "This is where I am" << std::endl;

	std::vector<SDL_Surface*> letterSurfaces;



	// Make Each letter as a surface

	int TextHeight = 200;
	int TextWidth = 0;

	for (int i = 0; i < textInput.size(); i++)
	{
		// This makes the letter as a new surface then pushes that onto the vector

		//RenderGlyph_Solid Gives a transparent Background
		letterSurfaces.push_back(TTF_RenderGlyph_Solid(newFont, textInput[i], SDL_Color{ 255,255,255,255 }));


	}



	for (int j = 0; j < letterSurfaces.size(); j++)
	{
		std::cout << letterSurfaces[j]->h << " " << letterSurfaces[j]->w << std::endl;
		TextWidth = TextWidth + letterSurfaces[j]->w;
	}

	TextWidth = TextWidth + 20;
	float indivualSpacing = letterSurfaces.size() / 20;

	SDL_Surface* letterCombinationSurface = SDL_CreateSurface(TextWidth, TextHeight, SDL_PIXELFORMAT_RGBA32);
	if (!letterCombinationSurface)
	{
		std::cout << "Issue here!" << std::endl;
	}

	int nextStartPoint = 0;
	for (int k = 0; k < letterSurfaces.size(); k++)
	{
		//Create a tempoary rectangle object - Each time we loop back to this the next start position changes
		SDL_Rect destRect = { nextStartPoint, TextWidth / letterSurfaces.size() ,TextHeight / letterSurfaces.size() };
		if (!&destRect)
		{
			std::cout << "DestRec not working" << std::endl;
		}
		//desRect specifies where to draw the letter on the combined surface
		SDL_BlitSurface(letterSurfaces[k], NULL, letterCombinationSurface, &destRect);

		//Next start point
		nextStartPoint = nextStartPoint + letterSurfaces[k]->w;
		//Cleaning up
		if (k == letterSurfaces.size()) { delete& destRect; }



	}

	return letterCombinationSurface;



	//Casting to float values the window



}

