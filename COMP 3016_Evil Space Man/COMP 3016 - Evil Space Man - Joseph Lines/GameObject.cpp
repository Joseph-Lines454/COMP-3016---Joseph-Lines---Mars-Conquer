#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <vector>

#include "MovementComponent.h"
#include "GraphicsComponent.h"
#include "GameObject.h"

//User Files

GameObject::GameObject(GraphicsComponent* graphicsIn, MovementComponent* movementSpaceMan, Health* healthSpaceMan) {


	//Here we can assign our different classes


	graphics = graphicsIn;
	//movement = movementIn;
	movement = movementSpaceMan;
	health = healthSpaceMan;
};


//if we pass in world here
void GameObject::update(SDL_Renderer* renderTemp, SDL_FRect* rectangleIn, Health* other)
{
	//So far, we are rendering movement and the graphic
	graphics->RenderUpdate(movement->Update(rectangleIn, health->GetHealth(), other), movement->GetRectangle(), renderTemp);
}


