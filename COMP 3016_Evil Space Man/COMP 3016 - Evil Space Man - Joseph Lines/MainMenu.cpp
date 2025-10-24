# include "MainMenu.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
//#include <SDL3/SDL3_ttf_SDL_ttf.h>
//int width, int height, SDL_WindowFlags flags, char* rendererName



void MainMenu::UpdateGame()
{
	SDL_Surface* bmp = SDL_LoadBMP("Assets/Backgrounds/Mars_Menu_Background.bmp");
	SDL_Texture* textureBackground = SDL_CreateTextureFromSurface(renderWindow, bmp);
	std::wstring text = L"Evil Space Man";
	
	TTF_Font* font = TTF_OpenFont("Assets/Fonts/RubikGlitch-Regular.ttf",16);
	if (textureBackground == NULL)
	{
		std::cout << "Could not be loaded" << std::endl;
		
	}

	SDL_RenderClear(renderWindow);
	SDL_RenderTexture(renderWindow, textureBackground, NULL, NULL);
	SDL_RenderPresent(renderWindow);
}
//Render Text in SDL -  This will take a while (https://glusoft.com/sdl3-tutorials/display-unicode-texts-sdl3-ttf/)
