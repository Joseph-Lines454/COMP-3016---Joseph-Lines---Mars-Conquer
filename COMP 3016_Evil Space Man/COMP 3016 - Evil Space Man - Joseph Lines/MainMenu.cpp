# include "MainMenu.h"
#include "Game.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
//#include <SDL3/SDL3_ttf_SDL_ttf.h>
//int width, int height, SDL_WindowFlags flags, char* rendererName

void RenderFont(std::wstring textInput, TTF_Font* newStyle);

void MainMenu::UpdateGame()
{
	//Loading the background image - Create a new function for this
	SDL_Surface* bmp = SDL_LoadBMP("Assets/Backgrounds/Mars_Menu_Background.bmp");
	SDL_Texture* textureBackground = SDL_CreateTextureFromSurface(renderWindow, bmp);
	
	
	
	std::wstring text = L"Evil Space Man";
	
	
	

	if (textureBackground == NULL)
	{
		std::cout << "Could not be loaded" << std::endl;
		
	}

	SDL_RenderClear(renderWindow);
	
	SDL_RenderTexture(renderWindow, textureBackground, NULL, NULL);
	SDL_RenderTexture(renderWindow, combinedTexture, NULL, rect);
	SDL_RenderPresent(renderWindow);
}
//Render Text in SDL -  This will take a while (https://glusoft.com/sdl3-tutorials/display-unicode-texts-sdl3-ttf/)
void MainMenu::RenderFont(std::wstring textInput, TTF_Font* newStyle, int* windowWidth, int* windowHeight)
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
		letterSurfaces.push_back(TTF_RenderGlyph_Solid(newStyle, textInput[i], SDL_Color{ 255,255,255,255}));
		
		
	}

	

	for (int j = 0; j < letterSurfaces.size(); j++)
	{
		//Find the highest height of each letter



		/*if (letterSurfaces[j]->h > TextHeight)
		{
			TextHeight = letterSurfaces[j]->h;
		}*/

		std::cout << letterSurfaces[j]->h << " " << letterSurfaces[j]->w << std::endl;
		TextWidth = TextWidth + letterSurfaces[j]->w;

		
	}

	//Spacing between letters
	TextWidth = TextWidth + 20;
	float indivualSpacing = letterSurfaces.size() / 20;
	//Create a combined surface with these paramaters

	SDL_FRect rectlocal = { TextWidth,TextHeight,SDL_PIXELFORMAT_RGBA32 };
	//rect = &rectlocal;

	

	//Making the larger surface tha the letters will be apart of
	//TextSurface = new SDL_FRect{5,50,static_cast<float>(TextWidth),static_cast<float>(TextHeight)};

	//Using SDL_Blit_Surface (copy of source surface to a destination surface)

	SDL_Surface* letterCombinationSurface = SDL_CreateSurface(TextWidth, TextHeight, SDL_PIXELFORMAT_RGBA32);
	if (!letterCombinationSurface)
	{
		std::cout << "Issue here!" << std::endl;
	}

	int nextStartPoint = 0;
	for (int k = 0; k < letterSurfaces.size(); k++)
	{
		//Create a tempoary rectangle object - Each time we loop back to this the next start position changes
		SDL_Rect destRect = { nextStartPoint, TextWidth / letterSurfaces.size() ,TextHeight / letterSurfaces.size()};
		if (!&destRect)
		{
			std::cout << "DestRec not working" << std::endl;
		}
		//desRect specifies where to draw the letter on the combined surface
		SDL_BlitSurface(letterSurfaces[k], NULL, letterCombinationSurface, &destRect);

		//Next start point
		nextStartPoint = nextStartPoint + letterSurfaces[k]->w;

		

		if (k == letterSurfaces.size()) { delete &destRect; }

		
		
	}
	
	

	combinedTexture = SDL_CreateTextureFromSurface(renderWindow, letterCombinationSurface);
	
	std::cout << "Here!"
		<< std::endl;

	//Casting to float values the window
	rect = new SDL_FRect{ static_cast<float>(combinedTexture->w) / 8,(static_cast<float>(*windowHeight) - combinedTexture->h) / 2 ,600.0f,200.0f};

}