#pragma once
#include <iostream>
#include "SpaceMan.h"
class Fruit
{

public:

	//include a reference to which object the fruit belongs to
	Fruit(int setDamage, std::string Name, SpaceMan& SpaceMan);
	void ShootFruit();
	void getGamage();


private:
	std::string fruit;
	int damage;


};