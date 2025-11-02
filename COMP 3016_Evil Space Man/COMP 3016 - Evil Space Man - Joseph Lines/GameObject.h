#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include "MovementComponent.h"
#include "GraphicsComponent.h"

#include "Health.h"
//Decoupling pattern, component
class GameObject
{
protected:

	//Pointer to the movement domain
	
	MovementComponent* movement;
	GraphicsComponent* graphics;
	Health* health;
public:
	//We need an update fuction here that allows for us to cycle 
	GameObject(GraphicsComponent* graphicsIn,MovementComponent* movementSpaceMan, Health* healthSpaceMan);
	GameObject() = default;
	// Some other paramaters may follow
	virtual void update(SDL_Renderer* renderTemp, SDL_FRect* rectangleIn, Health* other);

};