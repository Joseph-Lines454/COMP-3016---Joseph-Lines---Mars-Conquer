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
	
};

void GameObject::update(SDL_Renderer* renderTemp )
{

	
	SDL_RenderTexture(renderTemp, graphics->GetTexureExt(), NULL, movement->GetRectangle());
	std::string movementVar = movement->Update();
	if (movementVar != "")
	{
		//Changing the viewing position
		graphics->SetRectangle(movement->GetRectangle());

		//chaning to the correct move
		graphics->RenderUpdate(movementVar);
	}
	
	
}


