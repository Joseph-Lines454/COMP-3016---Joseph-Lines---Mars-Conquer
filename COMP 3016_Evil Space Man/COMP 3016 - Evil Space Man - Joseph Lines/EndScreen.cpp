#include "EndScreen.h"
#include <iostream>
#include <fstream>
#include <string>
#include "SDL3/SDL.h"
#include <chrono>

std::string EndScreen::ReadFromFile(std::chrono::seconds durationIn)
{
	
	
	Uint64 seconds;
	Uint64 secondsFile = 0;
	std::string TextIn;
	std::stringstream string;
	
	
	std::ifstream ReadFile("Score.txt");
	try
	{
		
		//should not produce an error because a line can be null - but in try catch anyway
		getline(ReadFile, TextIn);

		seconds = static_cast<Uint64>(durationIn.count());

		if (TextIn == "")
		{
			std::cout << "Null!" << "This is what is in that file: " << TextIn << std::endl;
		}
		if(TextIn != "")
		{
			//Converting to formats
			secondsFile = std::stoull(TextIn);

			std::cout << "Somthing is in the file: " << TextIn << std::endl;
			

			//string << "High Score: " << secondsFile << " Your score: " << seconds;

		}
		if (seconds > secondsFile)
		{
			WriteToFile(seconds);
		}
		string << "High Score: " << secondsFile << " Your score: " << seconds;
	}
	catch (Uint64 seconds)
	{
		std::cout << "Converison error" << std::endl;
		string << "Conversion Error from Unit 64 to string" << std::endl;
	}
	catch (...)
	{
		std::cout << "A unkown error has occured" << std::endl;
		string << "A unknown error has occured" << std::endl;
	}

	
	
	return string.str();

	ReadFile.close();

}

void EndScreen::WriteToFile(Uint64 seconds) {
	try
	{
		std::ofstream MyFile("Score.txt");

		MyFile << seconds;
	}
	catch (std::ofstream::failure fail)
	{
		std::cout << "Issue with writing to file!" << std::endl;
	}



}