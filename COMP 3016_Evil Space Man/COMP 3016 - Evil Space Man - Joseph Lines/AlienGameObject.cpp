#include "AlienGameObject.h"

AlienGameObject::AlienGameObject(GraphicsComponent* graphicsIn, AlienMov* movementSpaceMan, Health* healthSpaceMan)
{
	Graphics = graphicsIn;
	//movement = movementIn;
	movement = movementSpaceMan;
	HealthIn = healthSpaceMan;
}

void AlienGameObject::update(SDL_Renderer* renderTemp)
{
	std::cout << "SomeStuffHere" << std::endl;
	Graphics->RenderUpdate(movement->Update(), movement->GetRectangle(), renderTemp);
}