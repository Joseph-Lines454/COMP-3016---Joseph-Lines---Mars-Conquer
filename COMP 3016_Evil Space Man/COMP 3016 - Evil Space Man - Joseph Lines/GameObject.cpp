#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include "Functionality.h"
#include "MovementComponent.h"
#include "GraphicsComponent.h"


GameObject::GameObject(GraphicsComponent* graphicsIn, MovementComponent* movementIn) {


	//Here we can assign our different classes


	graphics = graphicsIn;
	movement = movementIn;
	



};

void GameObject::update()
{
	//First render of an image
	graphics->RenderImage(100,100);
}