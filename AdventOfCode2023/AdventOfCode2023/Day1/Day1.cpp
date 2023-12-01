#include "Day1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

void Puzzle1()
{
	std::fstream input;
	input.open("Day1/Day1Input.txt");
	std::string inputLine;

	int totalCalibrationValue = 0;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);
			char first = '0';
			char second = '0';
			for (int i = 0; i < inputLine.length(); i++)
			{
				if (isdigit(inputLine[i]))
				{
					first = inputLine[i];
					break;
				}
			}
			for (int j = inputLine.length(); j >= 0; j--)
			{
				if (isdigit(inputLine[j]))
				{
					second = inputLine[j];
					break;
				}
			}

			std::string calibrationValue{ first, second };

			totalCalibrationValue += std::stoi(calibrationValue);
		}
	}

	std::cout << totalCalibrationValue << std::endl;
}

void Puzzle2()
{

}