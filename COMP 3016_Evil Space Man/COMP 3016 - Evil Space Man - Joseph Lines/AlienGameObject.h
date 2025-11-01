#pragma once
#include "AlienMov.h"
#include "GraphicsComponent.h"
#include <SDL3/SDL.h>

class Health;

class AlienGameObject
{
private:
	AlienMov* movement;
	GraphicsComponent* Graphics;
	Health* HealthIn;
public:
	AlienGameObject(GraphicsComponent* graphicsIn, AlienMov* movementSpaceMan, Health* healthSpaceMan);
	void update(SDL_Renderer* renderTemp, SDL_FRect* other, Health* otherHealth);
	bool GetGameOver();
	bool SetGameOver();
};