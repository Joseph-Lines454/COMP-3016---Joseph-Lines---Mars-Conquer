# include "LifeForm.h"
#include "Game.h"
#include <SDL3/SDL.h>


void LifeForm::InitializeCreateObject(char* filePath, Game &gameobject)
{
	//passing in the Games Renderer and getting passing in the filePath image we want to use as a surface
	LifeFormTexture = SDL_CreateTextureFromSurface(gameobject.getRenderer(), SDL_LoadBMP(filePath));

}

//C 
void LifeForm::Attack() {
	




};