#pragma once
#include "GameObject.h"
#include "AlienMov.h"
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
	void update(SDL_Renderer* renderTemp);
};