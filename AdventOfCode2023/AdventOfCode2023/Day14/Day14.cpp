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

constexpr int HEIGHT = 10;
constexpr int WIDTH = 10;

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
	const std::vector<char> originalElements = elements;

	for (int cycle = 0; cycle < 1000000000; cycle++)
	{
		std::cout << cycle << std::endl;
		const std::vector<char> oldElements = elements;
		TiltNorth(elements);
		TiltWest(elements);
		TiltSouth(elements);
		TiltEast(elements);
		if (CompareElements(oldElements, elements))
		{
			std::cout << cycle << std::endl;
			break;
		}
	}

	for (int k = 0; k < elements.size(); k++)
	{
		if (k % 10 == 0)
		{
			std::cout << std::endl;
		}
		std::cout << elements[k];
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

void TiltNorth(std::vector<char>& elements)
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

void TiltSouth(std::vector<char>& elements)
{
	for (int i = elements.size() - 1; i >= 0; i--)
	{
		if (elements[i] == 'O')
		{
			bool canMove = true;
			int temp = i;
			while (canMove)
			{
				if (temp + WIDTH < (WIDTH * HEIGHT) && elements[temp + WIDTH] == '.')
				{
					elements[temp] = '.';
					elements[temp + WIDTH] = 'O';
					temp += WIDTH;
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


void TiltWest(std::vector<char>& elements)
{
	for (int i = 0; i < elements.size(); i++)
	{
		if (elements[i] == 'O')
		{
			bool canMove = true;
			int temp = i;
			while (canMove)
			{
				int edge = i - (i % WIDTH);
				if (temp - 1 >= edge && elements[temp - 1] == '.')
				{
					elements[temp] = '.';
					elements[temp - 1] = 'O';
					temp--;
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

void TiltEast(std::vector<char>& elements)
{
	for (int i = elements.size() - 1; i >= 0; i--)
	{
		if (elements[i] == 'O')
		{
			bool canMove = true;
			int temp = i;
			while (canMove)
			{
				int edge = ((int)(i / WIDTH) * WIDTH) + WIDTH;
				if (temp + 1 < edge && elements[temp + 1] == '.')
				{
					elements[temp] = '.';
					elements[temp + 1] = 'O';
					temp++;
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

bool CompareElements(const std::vector<char>& first, const std::vector<char>& second)
{
	if (first.size() != second.size())
	{
		return false;
	}
	
	for (int i = 0; i < first.size(); i++)
	{
		if (first[i] != second[i])
		{
			return false;
		}
	}

	return true;
}
