#pragma once


class LifeForm
{
public:
	LifeForm();
	
protected:
	//virtual functions to be inherited
	virtual void SpecialAttack() = 0;
	virtual void Attack();
	int health;
	int attackDamage;
	
	
	virtual void Shoot();
	
	
};