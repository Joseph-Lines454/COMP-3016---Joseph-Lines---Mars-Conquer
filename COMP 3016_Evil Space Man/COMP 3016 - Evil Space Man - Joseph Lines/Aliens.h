#include "LifeForm.h"
#include <iostream>

class Aliens : LifeForm
{
public:

	//Inherits from lifeform base class
	//Aliens() : LifeForm() {}
	
	//Inherit constructor from LifeForm
	Aliens() : LifeForm() {};

	//paramaters based on players movement will constitute movement
	void MoveAlien();

	//Alien Attack
	void AlienAttack();

	//Alien Defence
	

	//Getters and Setters
	

private:
	std::string alienName;


protected:

	



};