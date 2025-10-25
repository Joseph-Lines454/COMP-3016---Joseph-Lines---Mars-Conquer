#include "Game.h"
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
// Methods have been declared in the header file, Methods are being decleared here

Game::Game(const char* windowName, int width, int height, SDL_WindowFlags flags){ 
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





void Game::UpdateGame()
{

}

void Game::RenderFont(std::wstring textInput, TTF_Font* newStyle)
{

	
	std::vector<SDL_Surface*> letterSurfaces;

	

	// Make Each letter as a surface

	int TextHeight = 0;
	int TextWidth = 0;

	for (int i = 0; i < textInput.size(); i++)
	{
		// This makes the letter as a new surface then pushes that onto the vector
		letterSurfaces.push_back(TTF_RenderGlyph_LCD(newStyle, textInput[i], SDL_Color{ 233,235,250,255 }, SDL_Color{ 255,255,255,255 }));
	}
	
	for (int j = 0; j < letterSurfaces.size(); j++)
	{
		//Find the highest height of each letter
		
		if (letterSurfaces[j]->h > TextHeight)
		{
			TextHeight = letterSurfaces[j]->h;
		}

		TextWidth = TextWidth + letterSurfaces[j]->w;
	}
	//Spacing between letters
	TextWidth = TextWidth + 20;
	float indivualSpacing = letterSurfaces.size() / 20;
	//Create a combined surface with these paramaters


	//Making the larger surface tha the letters will be apart of
	SDL_FRect combinedsur = {5,50,static_cast<float>(TextWidth),static_cast<float>(TextHeight)};

	//Using SDL_Blit_Surface (copy of source surface to a destination surface)

	SDL_Surface* letterCombinationSurface = SDL_CreateSurface(TextHeight, TextHeight, SDL_PIXELFORMAT_RGBA32);

	int nextStartPoint = 0;
	for (int k = 0; k < letterSurfaces.size(); k++)
	{
		//Create a tempoary rectangle object - Each time we loop back to this the next start position changes
		SDL_Rect* destRect = new SDL_Rect{ nextStartPoint,letterSurfaces[k]->w,letterSurfaces[k]->h };

		//desRect specifies where to draw the letter on the combined surface


		//	I think that is wronf
		SDL_BlitSurface(letterSurfaces[k], NULL, letterCombinationSurface, destRect);

		//Next start point
		nextStartPoint = nextStartPoint + static_cast<int>(indivualSpacing) + letterSurfaces[k]->w;

		//Get rid of the surface - clean up after ourselves
		SDL_DestroySurface(letterSurfaces[k]);

		if (k == letterSurfaces.size()){delete destRect;}

		combinedTexture = SDL_CreateTextureFromSurface(renderWindow, letterCombinationSurface);
		SDL_DestroySurface(letterCombinationSurface);
	}
	
std::cout << "Worked!!" << std::endl;


}

