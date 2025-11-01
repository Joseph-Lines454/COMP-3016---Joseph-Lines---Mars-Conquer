#include "EndScreen.h"
#include <iostream>
#include <fstream>
void EndScreen::ReadFromFile()
{
	//Get the high score, if the high score is more than x, display 
	std::ofstream MyFile("Score.txt");

	MyFile << "This is some text that I am writting! 2" << std::endl;

	MyFile.close();
}

