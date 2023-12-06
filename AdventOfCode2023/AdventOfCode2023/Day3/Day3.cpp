#include "Day3.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <map>
#include <vector>
#include <set>

void Day3Puzzle1()
{
	constexpr int WIDTH = 140;

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

	int sumOfPartNumbers = 0;

	bool Adjacent = false;
	std::string number = "";
	for (int l = 0; l < lines.size(); l++)
	{
		if (!number.empty() && Adjacent)
		{
			sumOfPartNumbers += std::stoi(number);
		}
		Adjacent = false;
		number = "";
		for (int c = 0; c < WIDTH; c++)
		{
			if (isdigit(lines[l][c]))
			{
				number += lines[l][c];
				Adjacent |= AdjacentToSymbol(lines, l, c);
			}
			else
			{
				if (!number.empty() && Adjacent)
				{
					sumOfPartNumbers += std::stoi(number);
				}
				number = "";
				Adjacent = false;
			}
		}
	}

	std::cout << sumOfPartNumbers << std::endl;
}

void Day3Puzzle2()
{
	constexpr int WIDTH = 140;

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

	int sumOfGearNumbers = 0;

	std::map<int, std::vector<int>> adjacentToStar;
	bool adjacent = false;
	std::string number = "";
	std::set<int> positionOfStars;
	for (int l = 0; l < lines.size(); l++)
	{
		if (!number.empty() && adjacent)
		{
			for (const auto position : positionOfStars)
			{
				if (adjacentToStar.contains(position))
				{
					adjacentToStar[position].push_back(std::stoi(number));
				}
				else
				{
					adjacentToStar[position] = std::vector<int>{ std::stoi(number) };
				}
			}
		}
		adjacent = false;
		number = "";
		positionOfStars.clear();
		for (int c = 0; c < WIDTH; c++)
		{
			if (isdigit(lines[l][c]))
			{
				number += lines[l][c];
				adjacent |= AdjacentToStar(lines, l, c);
				positionOfStars.emplace(AdjacentToStar(lines, l, c));
			}
			else
			{
				if (!number.empty() && adjacent)
				{
					for (const auto position : positionOfStars)
					{
						if (adjacentToStar.contains(position))
						{
							adjacentToStar[position].push_back(std::stoi(number));
						}
						else
						{
							adjacentToStar[position] = std::vector<int>{ std::stoi(number) };
						}
					}
				}
				number = "";
				adjacent = false;
				positionOfStars.clear();
			}
		}
	}

	for (const auto element : adjacentToStar)
	{
		if (element.first != 0)
		{
			if (element.second.size() == 2)
			{
				int gearRatio = 1;
				for (const auto num : element.second)
				{
					gearRatio *= num;
				}
				sumOfGearNumbers += gearRatio;
			}
		}
	}

	std::cout << sumOfGearNumbers << std::endl;
}

bool AdjacentToSymbol(const std::vector<std::string>& rows, const int row, const int indexToCheck)
{
	const int numRows = 140;
	const int numElements = 140;

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

int AdjacentToStar(const std::vector<std::string>& rows, const int row, const int indexToCheck)
{
	const int numRows = 140;
	const int numElements = 140;

	for (int i : {-1, 0, 1})
	{
		for (int j : {-1, 0, 1})
		{
			if (row + i >= 0 && row + i < numRows && indexToCheck + j >= 0 && indexToCheck + j < numElements)
			{
				char elementToCheck = rows[row + i][indexToCheck + j];
				if (elementToCheck == '*')
				{
					return ((row + i) * 140) + indexToCheck + j;
				}
			}
		}
	}

	return 0;
}
