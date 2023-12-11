#include "Day11.h"
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

void Day11Puzzle1()
{
	std::vector<Location> universe;

	std::fstream input;
	input.open("../AdventOfCode2023/Day11/Day11Input.txt");
	std::string inputLine;

	std::unordered_set<int> nonEmptyColumns;
	int currentRow = 0;
	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			bool hasGalaxy = false;
			for (int c = 0; c < inputLine.length(); c++)
			{
				if (inputLine[c] == '#')
				{
					universe.push_back(Location(c, currentRow));
					nonEmptyColumns.emplace(c);
					hasGalaxy = true;
				}
			}
			if (!hasGalaxy)
			{
				currentRow++;
			}
			currentRow++;
		}
	}

	for (int location = 0; location < universe.size(); location++)
	{
		int tempX = universe[location].x;
		for (int i = 0; i < universe[location].x; i++)
		{
			if (!nonEmptyColumns.contains(i))
			{
				tempX++;
			}
		}
		universe[location].x = tempX;
	}

	int sumOfLengths = 0;
	for (int row = 0; row < universe.size() - 1; row++)
	{
		for (int other = row + 1; other < universe.size(); other++)
		{
			sumOfLengths += DistanceBetweenTwoPoints(universe[row], universe[other]);
		}
	}

	std::cout << sumOfLengths << std::endl;
}

void Day11Puzzle2()
{
	std::vector<Location> universe;

	std::fstream input;
	input.open("../AdventOfCode2023/Day11/Day11Input.txt");
	std::string inputLine;

	std::unordered_set<int> nonEmptyColumns;
	int currentRow = 0;
	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			bool hasGalaxy = false;
			for (int c = 0; c < inputLine.length(); c++)
			{
				if (inputLine[c] == '#')
				{
					universe.push_back(Location(c, currentRow));
					nonEmptyColumns.emplace(c);
					hasGalaxy = true;
				}
			}
			if (!hasGalaxy)
			{
				currentRow += 999999;
			}
			currentRow++;
		}
	}

	for (int location = 0; location < universe.size(); location++)
	{
		int tempX = 0;
		for (int i = 0; i < universe[location].x; i++)
		{
			if (!nonEmptyColumns.contains(i))
			{
				tempX++;
			}
		}
		universe[location].x += (tempX * 999999);
	}

	long long sumOfLengths = 0;
	for (int row = 0; row < universe.size() - 1; row++)
	{
		for (int other = row + 1; other < universe.size(); other++)
		{
			sumOfLengths += DistanceBetweenTwoPoints(universe[row], universe[other]);
		}
	}

	std::cout << sumOfLengths << std::endl;
}

int DistanceBetweenTwoPoints(Location first, Location second)
{
	return abs(first.x - second.x) + abs(first.y - second.y);
}
