# include "MainMenu.h"
#include "Game.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include <SDL3/SDL_events.h>
//#include <SDL3/SDL3_ttf_SDL_ttf.h>
//int width, int height, SDL_WindowFlags flags, char* rendererName

SDL_Renderer* MainMenu::GetRenderWindow() {
	return renderWindow;
};

SDL_Window* MainMenu::GetWindow() {
	return newWindow;
}


bool MainMenu::PlayButtonCheck()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	
	if (event.type == SDL_EVENT_KEY_DOWN || event.type == SDL_EVENT_KEY_UP)
	{
		return true;
	}


	return false;

}

void MainMenu::UpdateGame()
{
	//Loading the background image for the game
	SDL_Surface* bmp = SDL_LoadBMP("Assets/Backgrounds/Mars_Menu_Background.bmp");
	SDL_Texture* textureBackground = SDL_CreateTextureFromSurface(renderWindow, bmp);

	PlayButtonCheck();

	SDL_RenderClear(renderWindow);
	
	SDL_RenderTexture(renderWindow, textureBackground, NULL, NULL);
	SDL_RenderTexture(renderWindow, combinedTextureTitle, NULL, rectTitle);
	SDL_RenderTexture(renderWindow, combinedTexturePressPlay, NULL, rectPressPlay);
	SDL_RenderPresent(renderWindow);
}

//Code for the TitleText
void MainMenu::SetTitleText(std::wstring textIn, int setXpos, int setYpos)
{
	//call render font then 
	//Getting the surface Back
	SDL_Surface* surfaceTemp = RenderFont(textIn);
	combinedTextureTitle  = SDL_CreateTextureFromSurface(renderWindow, surfaceTemp);
	SDL_DestroySurface(surfaceTemp);
	//some paramters are needed for this function for press any key
	rectTitle = new SDL_FRect{ static_cast<float>(combinedTextureTitle->w) / setXpos,(static_cast<float>(windowHeight) - combinedTextureTitle->h) / setYpos ,600.0f,200.0f };
}

//Code for the Key indication
void MainMenu::SetPressPlay(std::wstring textIn, int setXpos, int setYpos)
{
	SDL_Surface* surfaceTemp = RenderFont(textIn);
	combinedTexturePressPlay = SDL_CreateTextureFromSurface(renderWindow, surfaceTemp);
	SDL_DestroySurface(surfaceTemp);
	//some paramters are needed for this function for press any key
	rectPressPlay = new SDL_FRect{ static_cast<float>(combinedTextureTitle->w) / setXpos,(static_cast<float>(windowHeight) - combinedTextureTitle->h) / setYpos ,200.0f,100.0f };


}


//Render Text in SDL -  This will take a while (https://glusoft.com/sdl3-tutorials/display-unicode-texts-sdl3-ttf/)
