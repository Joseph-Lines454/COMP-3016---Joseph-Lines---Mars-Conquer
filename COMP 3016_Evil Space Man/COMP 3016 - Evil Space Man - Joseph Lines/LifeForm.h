#pragma once
#include <SDL3/SDL.h>
#include <iostream>
class LifeForm
{
public:
	LifeForm();
	
protected:
	//virtual functions to be inherited
	virtual void SpecialAttack() = 0;
	virtual void Attack();
	virtual void InitializeCreateObject(char* filePath, Game& gameeobject);
	int health;
	int attackDamage;
	SDL_Texture* LifeFormTexture = nullptr;
	
	virtual void Shoot();
	
	
};