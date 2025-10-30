#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include "Functionality.h"
#include "MovementComponent.h"
#include "GraphicsComponent.h"

//Decoupling pattern, component
class GameObject
{
private:
	
	//We want to attach the Graphics and input method to this class
	//For now lets just use a object vairable
	//Components Have to be added to the game Object like now

	std::vector<BaseClass>* Component;

	//Pointer to the movement domain
	
	MovementComponent* movement;
	GraphicsComponent* graphics;
public:
	//We need an update fuction here that allows for us to cycle 
	GameObject(GraphicsComponent* graphicsIn,MovementComponent* movementSpaceMan);
	// Some other paramaters may follow
	void update();

};