#include "Day3.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <map>
#include <vector>

void Day3Puzzle1()
{
	constexpr int WIDTH = 10;
	constexpr int HEIGHT = 10;

	std::vector<std::string> lines;

	std::fstream input;
	input.open("../AdventOfCode2023/Day3/Day3Input.txt");
	std::string inputLine;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);
			lines.push_back(inputLine);
		}
	}

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (isdigit(lines[i][j]) && AdjacentToSymbol(lines, i, j))
			{
				std::cout << lines[i][j] << std::endl;
			}
		}
	}
}

void Day3Puzzle2()
{
}

bool AdjacentToSymbol(const std::vector<std::string>& rows, const int row, const int indexToCheck)
{
	const int numRows = 10;
	const int numElements = 10;

	for (int i : {-1, 0, 1})
	{
		for (int j : {-1, 0, 1})
		{
			if (row + i >= 0 && row + i < numRows && indexToCheck + j >= 0 && indexToCheck + j < numElements)
			{
				char elementToCheck = rows[row + i][indexToCheck + j];
				if (elementToCheck != '.' and !isdigit(elementToCheck))
				{
					return true;
				}
			}
		}
	}

	return false;
}
