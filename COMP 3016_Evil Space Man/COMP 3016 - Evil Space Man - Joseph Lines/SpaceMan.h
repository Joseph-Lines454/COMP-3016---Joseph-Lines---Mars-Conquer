#pragma once
#include "LifeForm.h"
#include <iostream>


class SpaceMan : LifeForm
{
public:
	//inhert the constructor - paramaters will follow when initalizing due to SDL
	SpaceMan() : LifeForm() {};
	
	virtual void SpecialAttack();

	virtual void shoot();

	void SpaceManAttack();

private: 
	std::string spaceManName;

};