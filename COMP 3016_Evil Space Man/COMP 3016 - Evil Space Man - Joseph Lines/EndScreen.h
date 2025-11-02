#pragma once
#include "Game.h"
#include <iostream>
#include <fstream>
#include <chrono>



class EndScreen : public Game
{
public:
	std::string ReadFromFile(std::chrono::seconds durationIn);
private:
	void WriteToFile(Uint64 seconds);
	
};