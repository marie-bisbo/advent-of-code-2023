#include "Day9.h"
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

void Day9Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day9/Day9Input.txt");
	std::string inputLine;

	long long totalNextValues = 0;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			std::vector<std::vector<int>> differences;

			std::stringstream ss(inputLine);
			std::string temp;
			std::vector<int> originalNumbers;
			while (std::getline(ss, temp, ' '))
			{
				originalNumbers.push_back(std::stoi(temp));
			}
			differences.push_back(originalNumbers);

			int currentIndex = 0;
			bool allZero = false;
			while (!allZero)
			{
				allZero = true;
				std::vector<int> currentNumbers;
				for (int i = 1; i < differences[currentIndex].size(); i++)
				{
					int difference = differences[currentIndex][i] - differences[currentIndex][i - 1];
					currentNumbers.push_back(difference);
					if (difference != 0)
					{
						allZero = false;
					}
				}
				differences.push_back(currentNumbers);
				currentIndex++;
			}

			long long nextNumber = 0;
			for (const auto nums : differences)
			{
				nextNumber += nums[nums.size() - 1];
			}

			totalNextValues += nextNumber;
		}
	}

	std::cout << totalNextValues << std::endl;
}

void Day9Puzzle2()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day9/Day9Input.txt");
	std::string inputLine;

	long long totalFirstValues = 0;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			std::vector<std::vector<int>> differences;

			std::stringstream ss(inputLine);
			std::string temp;
			std::vector<int> originalNumbers;
			while (std::getline(ss, temp, ' '))
			{
				originalNumbers.push_back(std::stoi(temp));
			}
			differences.push_back(originalNumbers);

			int currentIndex = 0;
			bool allZero = false;
			while (!allZero)
			{
				allZero = true;
				std::vector<int> currentNumbers;
				for (int i = 1; i < differences[currentIndex].size(); i++)
				{
					int difference = differences[currentIndex][i] - differences[currentIndex][i - 1];
					currentNumbers.push_back(difference);
					if (difference != 0)
					{
						allZero = false;
					}
				}
				differences.push_back(currentNumbers);
				currentIndex++;
			}

			int currentDifference = 0;
			for (int difference = differences.size() - 1; difference >= 0; difference--)
			{
				currentDifference = differences[difference][0] - currentDifference;
			}

			totalFirstValues += currentDifference;
		}
	}

	std::cout << totalFirstValues << std::endl;
}
