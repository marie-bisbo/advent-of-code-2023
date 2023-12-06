#include "Day4.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <math.h>
#include <map>

struct ScratchCard
{
	int amount = 0;
	int winningNumbers = 0;
};

void Day4Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day4/Day4Input.txt");
	std::string inputLine;

	int totalScore = 0;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::vector<int> winningNumbers;
			std::vector<int> myNumbers;
			int numWinningNumbers = 0;

			std::getline(input, inputLine);
			int start = inputLine.find(':') + 2;
			int midPoint = inputLine.find('|') + 2;
			for (int i = start; i < midPoint - 2; i += 3)
			{
				winningNumbers.push_back(std::stoi(inputLine.substr(i, 2)));
			}

			for (int j = midPoint; j < inputLine.length(); j += 3)
			{
				myNumbers.push_back(std::stoi(inputLine.substr(j, 2)));
			}

			for (const auto num : winningNumbers)
			{
				if (std::find(myNumbers.begin(), myNumbers.end(), num) != myNumbers.end())
				{
					numWinningNumbers++;
				}
			}

			totalScore += pow(2, numWinningNumbers - 1);
		}
	}

	std::cout << totalScore << std::endl;
}

void Day4Puzzle2()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day4/Day4Input.txt");
	std::string inputLine;

	int totalScratchCards = 0;
	std::vector<ScratchCard> scratchCards;
	int counter = 0;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::vector<int> winningNumbers;
			std::vector<int> myNumbers;
			int numWinningNumbers = 0;
			int amountScratchCards = 1;

			std::getline(input, inputLine);
			int start = inputLine.find(':') + 2;
			int midPoint = inputLine.find('|') + 2;
			for (int i = start; i < midPoint - 2; i += 3)
			{
				winningNumbers.push_back(std::stoi(inputLine.substr(i, 2)));
			}

			for (int j = midPoint; j < inputLine.length(); j += 3)
			{
				myNumbers.push_back(std::stoi(inputLine.substr(j, 2)));
			}

			for (const auto num : winningNumbers)
			{
				if (std::find(myNumbers.begin(), myNumbers.end(), num) != myNumbers.end())
				{
					numWinningNumbers++;
				}
			}

			for (int s = 0; s < scratchCards.size(); s++)
			{
				if ((counter - s) <= scratchCards[s].winningNumbers)
				{
					amountScratchCards += scratchCards[s].amount;
				}
			}

			counter++;

			ScratchCard newCard{ amountScratchCards, numWinningNumbers };
			scratchCards.push_back(newCard);
		}
	}

	for (const auto sc : scratchCards)
	{
		totalScratchCards += sc.amount;
	}

	std::cout << totalScratchCards << std::endl;
}
