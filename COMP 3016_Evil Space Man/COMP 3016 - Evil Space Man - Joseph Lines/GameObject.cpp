#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include "Functionality.h"
#include "MovementComponent.h"
#include "GraphicsComponent.h"
#include "GameObject.h"

GameObject::GameObject(GraphicsComponent* graphicsIn, MovementComponent* movementSpaceMan) {


	//Here we can assign our different classes


	graphics = graphicsIn;
	//movement = movementIn;
	movement = movementSpaceMan;
	graphics->RenderInital();
};

void GameObject::update()
{
	std::string movementVar = movement->Update();
	if (movementVar != "")
	{
		graphics->RenderUpdate(movementVar);
	}
	
	
}


