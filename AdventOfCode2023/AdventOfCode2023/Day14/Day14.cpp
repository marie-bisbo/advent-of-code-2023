#include "Day14.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <math.h>
#include <map>
#include <unordered_set>
#include <cstdlib>
#include <sstream>

constexpr int HEIGHT = 100;
constexpr int WIDTH = 100;

void Day14Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day14/Day14Input.txt");
	std::string inputLine;

	int totalLoad = 0;

	std::vector<char> elements;
	if (input.is_open())
	{
		std::vector<std::string> rows;
		while (!input.eof())
		{
			std::getline(input, inputLine);

			for (const char c : inputLine)
			{
				elements.push_back(c);
			}
		}
	}

	for (int i = 0; i < elements.size(); i++)
	{
		if (elements[i] == 'O')
		{
			bool canMove = true;
			int temp = i;
			while (canMove)
			{
				if (temp - WIDTH >= 0 && elements[temp - WIDTH] == '.')
				{
					elements[temp] = '.';
					elements[temp - WIDTH] = 'O';
					temp -= WIDTH;
				}
				else
				{
					canMove = false;
					break;
				}
			}
		}
	}

	for (int j = 0; j < elements.size(); j++)
	{
		if (elements[j] == 'O')
		{
			int load = HEIGHT - (int)(j / WIDTH);
			totalLoad += load;
		}
	}

	std::cout << totalLoad << std::endl;
}

void Day14Puzzle2()
{
}

void TiltNorth(std::vector<char> elements)
{
	for (int i = 0; i < elements.size(); i++)
	{
		if (elements[i] == 'O')
		{
			bool canMove = true;
			int temp = i;
			while (canMove)
			{
				if (temp - WIDTH >= 0 && elements[temp - WIDTH] == '.')
				{
					elements[temp] = '.';
					elements[temp - WIDTH] = 'O';
					temp -= WIDTH;
				}
				else
				{
					canMove = false;
					break;
				}
			}
		}
	}

}

void TiltWest(std::vector<char> elements)
{

}

void TiltSouth(std::vector<char> elements)
{

}

void TiltEast(std::vector<char> elements)
{

}
