#include "Day12.h"
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

void Day12Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day12/Day12Input.txt");
	std::string inputLine;
	if (input.is_open())
	{
		std::string springRecords = "";
		std::string contiguousBrokenSprings = "";
		while (!input.eof())
		{
			std::getline(input, inputLine);

			int index = inputLine.find(' ');
			springRecords = inputLine.substr(0, index);
			contiguousBrokenSprings = inputLine.substr(index + 1);
			std::vector<int> numbers;
			std::stringstream ss(contiguousBrokenSprings);
			std::string temp;
			while (std::getline(ss, temp, ','))
			{
				numbers.push_back(std::stoi(temp));
			}

			int validConfigurations = 0;
			std::vector<std::string> groups;
			std::string currentGroup = "";
			for (int i = 0; i < springRecords.length(); i++)
			{
				if (springRecords[i] == '?' || springRecords[i] == '#')
				{
					currentGroup += springRecords[i];
				}
				else
				{
					groups.push_back(currentGroup);
					currentGroup = "";
				}
			}
			groups.push_back(currentGroup);

			int currentNumIndex = 0;
			for (const auto group : groups)
			{
				for (int count = 0; count < numbers[currentNumIndex]; count++)
				{
				}
			}
		}
	}
}

void Day12Puzzle2()
{
}
