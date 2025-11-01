#pragma once

#include "AlienGameObject.h"
#include "Health.h"




AlienGameObject::AlienGameObject(GraphicsComponent* graphicsIn, AlienMov* movementSpaceMan, Health* healthSpaceMan)
{
	Graphics = graphicsIn;
	//movement = movementIn;
	movement = movementSpaceMan;
	HealthIn = healthSpaceMan;
}

void AlienGameObject::Update(SDL_Renderer* renderTemp, SDL_FRect* other, Health* otherHealth, bool Coutch)
{
	std::cout << HealthIn->GetHealth();
	Graphics->RenderUpdate(movement->Update(other, HealthIn->GetHealth(), otherHealth,Coutch), movement->GetRectangle(), renderTemp);
}