#include "Day16.h"
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

void Day16Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day16/Day16Input.txt");
	std::string inputLine;

	std::vector<char> elements;
	std::unordered_set<int> energisedTiles;
	constexpr int GRID_SIZE = 10;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			for (const char c : inputLine)
			{
				elements.push_back(c);
			}
		}
	}

	std::vector<int> beams;
	beams.push_back(0);
	for (int c = 0; c < elements.size();)
	{
		energisedTiles.emplace(c);
		if (elements[c] == '\\')
		{
			c += GRID_SIZE;
		}
		else if (elements[c] == '/')
		{
			c -= GRID_SIZE;
		}
		else if (elements[c] == '|')
		{
			c += GRID_SIZE;
		}
		else
		{
			c++;
		}
	}
}

void Day16Puzzle2()
{
}
