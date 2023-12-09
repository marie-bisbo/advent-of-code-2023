#include "Day6.h"
#include <cstring>
#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <math.h>
#include <map>


void Day6Puzzle1()
{
	std::map<int, int> timeToDistance{ {58, 478}, {99, 2232}, {64, 1019}, {69, 1071} };

	int totalWaysBeaten = 1;
	for (const auto race : timeToDistance)
	{
		int time = race.first;
		int distanceRecord = race.second;
		int waysBeaten = 0;

		for (int i = 1; i <= time; i++)
		{
			int distance = i * (time - i);
			if (distance > distanceRecord)
			{
				waysBeaten++;
			}
		}
		totalWaysBeaten *= waysBeaten;
	}

	std::cout << totalWaysBeaten << std::endl;
}

void Day6Puzzle2()
{
	long long time = 58996469;
	long long distanceRecord = 478223210191071;
	long long firstWin = 0;

	for (long long i = 1; i <= time; i++)
	{
		long long distance = i * (time - i);
		if (distance > distanceRecord)
		{
			firstWin = i;
			break;
		}
	}

	long long waysBeaten = time - (2 * firstWin) + 1;

	std::cout << waysBeaten << std::endl;
}
