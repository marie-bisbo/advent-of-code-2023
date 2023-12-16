#include "Day15.h"
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

struct Lens
{
	std::string label = "";
	int focalLength = 0;
};

struct Box
{
	int number = 0;
	std::vector<Lens> Lenses;

	void AddLens(Lens& lens, int boxNumber)
	{
		if (boxNumber != number)
		{
			return;
		}
		for (auto& l : Lenses)
		{
			if (l.label == lens.label)
			{
				l.focalLength = lens.focalLength;
				return;
			}
		}

		// std::cout << "Box: " << boxNumber << ", Label: " << lens.label << ", focal length: " << lens.focalLength << std::endl;
		Lenses.push_back(lens);
	}
};

void Day15Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day15/Day15Input.txt");
	std::string inputLine;

	int totalHashValues = 0;
	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			std::vector<std::string> elements;

			std::stringstream ss(inputLine);
			std::string temp;
			while (std::getline(ss, temp, ','))
			{
				elements.push_back(temp);
			}

			for (const auto elem : elements)
			{
				int hashValue = 0;
				for (const char c : elem)
				{
					int asciiValue = (int)c + hashValue;
					asciiValue *= 17;
					int remainder = asciiValue - ((int)(asciiValue / 256) * 256);
					hashValue = remainder;
				}
				totalHashValues += hashValue;
			}
		}
	}

	std::cout << totalHashValues << std::endl;
}

void Day15Puzzle2()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day15/Day15Input.txt");
	std::string inputLine;

	std::vector<Box> boxes;
	for (int num = 0; num < 256; num++)
	{
		boxes.push_back(Box{ num });
	}

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			std::vector<std::string> elements;

			std::stringstream ss(inputLine);
			std::string temp;
			while (std::getline(ss, temp, ','))
			{
				elements.push_back(temp);
			}

			for (const auto& elem : elements)
			{
				std::string label = "";
				int hashValue = 0;
				char operationType = '0';
				for (const char c : elem)
				{
					if (c == '=' || c == '-')
					{
						operationType = c;
						break;
					}
					label += c;
					int asciiValue = (int)c + hashValue;
					asciiValue *= 17;
					int remainder = asciiValue - ((int)(asciiValue / 256) * 256);
					hashValue = remainder;
				}

				if (operationType == '=')
				{
					Lens lens { label, elem[elem.size() - 1] - '0' };
					for (auto& box : boxes)
					{
						box.AddLens(lens, hashValue);
					}
				}
				else if (operationType == '-')
				{
					for (auto& box : boxes)
					{
						if (box.number == hashValue)
						{
							for (int lens = 0; lens < box.Lenses.size(); lens++)
							{
								if (box.Lenses[lens].label == label)
								{
									box.Lenses.erase(box.Lenses.begin() + lens);
									break;
								}
							}
						}
					}
				}
			}
		}
	}

	int totalFocusingPower = 0;
	for (int box = 0; box < boxes.size(); box++)
	{
		for (int lens = 0; lens < boxes[box].Lenses.size(); lens++)
		{
			totalFocusingPower += (box + 1) * (lens + 1) * boxes[box].Lenses[lens].focalLength;
		}
	}
	
	std::cout << totalFocusingPower << std::endl;
}
