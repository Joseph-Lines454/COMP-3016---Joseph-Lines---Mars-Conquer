#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include "MovementComponent.h"
#include "GraphicsComponent.h"
#include "Collision.h"
#include "Health.h"
//Decoupling pattern, component
class GameObject
{
protected:
	
	//We want to attach the Graphics and input method to this class
	//For now lets just use a object vairable
	//Components Have to be added to the game Object like now

	

	//Pointer to the movement domain
	
	MovementComponent* movement;
	GraphicsComponent* graphics;
	Health* health;
public:
	//We need an update fuction here that allows for us to cycle 
	GameObject(GraphicsComponent* graphicsIn,MovementComponent* movementSpaceMan, Health* healthSpaceMan);
	GameObject() = default;
	// Some other paramaters may follow
	virtual void update(SDL_Renderer* renderTemp);

};