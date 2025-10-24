#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include "Functionality.h"
class GameObject
{
private:
	// A component can not be of a template type - therfore we need to use polymorphic casting

	std::vector<BaseClass>* Component;

public:

	//Templates to allow for any time of class to be inputted
	
	
	//template <class T>

	//void InputValues(T value)
	//{

		//value = (BaseClass)value
		//Component->push_back(value);
		//Looping through untill we reach the final memory address

		/*
		int FinalAdress = classInput + classInput.size();
		for (classInput < FinalAdress; classInput++)
		{
			//Dereferencing and adding it to the components vector
			Components->push_back(*classInput);
		}*/

	//}







};