#include "Instructions.h"
#include "Game.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>
#include <vector>



std::vector<SDL_FRect*> Instructions::GetViewText()
{
	return viewText;
}

std::vector<SDL_Texture*> Instructions::GetTextures()
{
	return combinedTextureTitle;
}


void Instructions::UpdateGame()
{
	//Loading the background image for the game
	SDL_Surface* bmp = SDL_LoadBMP("Assets/Backgrounds/Mars_Menu_Background.bmp");
	SDL_Texture* textureBackground = SDL_CreateTextureFromSurface(renderWindow, bmp);



	SDL_RenderClear(renderWindow);

	SDL_RenderTexture(renderWindow, textureBackground, NULL, NULL);
	

	for (int i = 0; i < viewText.size(); i++)
	{
		SDL_RenderTexture(renderWindow, combinedTextureTitle[i], NULL, viewText[i]);
		
	}
	SDL_RenderPresent(renderWindow);
	SDL_Delay(1000);
	
}

void Instructions::InstructionText(SDL_Renderer* renderTemp)
{
	renderWindow = renderTemp;

	std::vector<std::wstring> Text;
	std::cout << "ISSUE!" << std::endl;
	//Setting the text for the game
	Text.push_back(L"You are an evil spaceMan");
	Text.push_back(L"Your mission is to exterminate all life from this planet");
	Text.push_back(L"You must defeat the three hero's of this planet");
	Text.push_back(L"Good Luck!");
	
	int currentPositionViewY = 20;
	std::cout << Text.size() << std::endl;
	
	
	
	
	for (int i = 0; i < Text.size(); i++)
	{
		std::cout << "ViewText: " << viewText.size() << "Texture: " << combinedTextureTitle.size() << std::endl;
		//combinedTextureTitle[i] = { new SDL_Texture };
		//viewText[i] = { new SDL_FRect };
		//Creating a new surface and assiging the renderWindow 
		SDL_Surface* surfaceTemp = RenderFont(Text[i]);
		std::cout << surfaceTemp->w << std::endl;
		int width = 0;
		if (surfaceTemp->w > 700)
		{
			width = 800;
		}
		else if (surfaceTemp->w < 600)
		{
			width = 400;
		}
		else
		{
			width = 700;
		}

		SDL_FRect* rectTemp = new SDL_FRect{ 0, static_cast<float>(currentPositionViewY) ,static_cast<float>(width),100.0f };
		SDL_Texture* textTemp = SDL_CreateTextureFromSurface(renderWindow, surfaceTemp);
		combinedTextureTitle.push_back(textTemp);
		viewText.push_back(rectTemp);
		// Change the viewing space 
		//viewText[i] = rectTemp;
		currentPositionViewY = currentPositionViewY + 100;
	}

	std::cout << "Got here!" << std::endl;
	


}


