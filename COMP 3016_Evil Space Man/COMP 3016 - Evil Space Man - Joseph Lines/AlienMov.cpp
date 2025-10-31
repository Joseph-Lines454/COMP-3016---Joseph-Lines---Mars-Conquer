#include <map>
#include <iostream>
#include "SDL3/SDL.h"
#include <map>
#include "AlienMov.h"
AlienMov::AlienMov(int XstartPos)
{
	int windowWidth, windowHeight = 0;

	std::cout << windowHeight << std::endl;
	recttangleMove = new SDL_FRect{ static_cast<float>(XstartPos),800 - 150,150.0f,150.0f };
}
std::string AlienMov::Update()
{

	currentposX++;
	recttangleMove->x = currentposX;
	return "SpaceMan_Walking_East";
};




SDL_FRect* AlienMov::GetRectangle()
{
	return recttangleMove;
}