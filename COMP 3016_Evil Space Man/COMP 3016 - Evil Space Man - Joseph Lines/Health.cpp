#pragma once
#include "Health.h"


Health::Health(int health)
{
	this->health = health;
}

int Health::GetHealth() {
	return health;
};

void Health::SetHealth(int health)
{
	this->health = this->health - health;
}

void Health::ResetHealth(int health)
{
	this->health = health;
}