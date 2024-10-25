#include "Day18.h"
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
#include <list>
#include <algorithm>

struct Dig
{
	char direction;
	int amount;
};

struct Position
{
	int x = 0;
	int y = 0;
};

void Day18Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day18/Day18Input.txt");
	std::string inputLine;

	std::vector<Dig> digs;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			std::stringstream ss(inputLine);
			std::string temp;
			int counter = 0;
			Dig dig;
			while (std::getline(ss, temp, ' '))
			{
				if (counter == 0)
				{
					dig.direction = temp[0];
				}
				else if (counter == 1)
				{
					dig.amount = std::stoi(temp);
				}
				counter++;
			}
			digs.push_back(dig);
		}
	}

	std::vector<Position> positions;
	Position currentPosition = Position{};
	positions.push_back(currentPosition);
	for (const auto dig : digs)
	{
		if (dig.direction == 'U')
		{
			for (int i = 1; i <= dig.amount; i++)
			{
				Position newPosition{ currentPosition.x, currentPosition.y + i };
				positions.push_back(newPosition);
			}
		}
		else if (dig.direction == 'D')
		{
			for (int i = 1; i <= dig.amount; i++)
			{
				Position newPosition{ currentPosition.x, currentPosition.y - i };
				positions.push_back(newPosition);
			}
		}
		else if (dig.direction == 'R')
		{
			for (int i = 1; i <= dig.amount; i++)
			{
				Position newPosition{ currentPosition.x + i, currentPosition.y };
				positions.push_back(newPosition);
			}
		}
		else if (dig.direction == 'L')
		{
			for (int i = 1; i <= dig.amount; i++)
			{
				Position newPosition{ currentPosition.x - i, currentPosition.y };
				positions.push_back(newPosition);
			}
		}

		currentPosition = positions[positions.size() - 1];
	}

	int totalCubicMetresOfLava = 0;
	std::sort(positions.begin(), positions.end(), [](const Position& A, const Position& B) { return A.y < B.y; });
	std::unordered_set<int> rows;
	for (const auto position : positions)
	{
		rows.emplace(position.y);
	}

	for (const auto row : rows)
	{
		std::vector<int> xPositions;
		for (const auto position : positions)
		{
			if (position.y == row)
			{
				xPositions.push_back(position.x);
			}

			std::sort(xPositions.begin(), xPositions.end());
			totalCubicMetresOfLava += abs(xPositions[0] - xPositions[xPositions.size() - 1]);
		}
	}

	std::cout << totalCubicMetresOfLava << std::endl;
}

void Day18Puzzle2()
{
}
