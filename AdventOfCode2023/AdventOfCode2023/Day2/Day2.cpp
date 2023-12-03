#include "Day2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <map>
#include <regex>

void Day2Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day2/Day2Input.txt");
	std::string inputLine;
	int idCounter = 0;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			std::regex regexpr("blue|red|green");
			std::string originalInput = inputLine;
			bool possible = true;
			for (std::smatch match; std::regex_search(inputLine, match, regexpr);)
			{
				const std::string amountOf = inputLine.substr(match.position() - 3, 3);
				int amount = std::stoi(amountOf);
				if (match.str() == "red")
				{
					if (amount > 12)
					{
						possible = false;
						break;
					}
				}
				else if (match.str() == "blue")
				{
					if (amount > 14)
					{
						possible = false;
						break;
					}
				}
				else if (match.str() == "green")
				{
					if (amount > 13)
					{
						possible = false;
						break;
					}
				}
				
				inputLine = match.suffix();
			}

			if (possible)
			{
				int gameId = std::stoi(originalInput.substr(5, 3));
				idCounter += gameId;
			}
		}
	}

	std::cout << idCounter << std::endl;
}

void Day2Puzzle2()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day2/Day2Input.txt");
	std::string inputLine;
	int totalPower = 0;

	if (input.is_open())
	{
		while (!input.eof())
		{
			int red = 0;
			int blue = 0;
			int green = 0;

			std::getline(input, inputLine);

			std::regex regexpr("blue|red|green");
			std::string originalInput = inputLine;
			bool possible = true;
			for (std::smatch match; std::regex_search(inputLine, match, regexpr);)
			{
				const std::string amountOf = inputLine.substr(match.position() - 3, 3);
				int amount = std::stoi(amountOf);

				if (match.str() == "red")
				{
					if (amount > red)
					{
						red = amount;
					}
				}
				else if (match.str() == "blue")
				{
					if (amount > blue)
					{
						blue = amount;
					}
				}
				else if (match.str() == "green")
				{
					if (amount > green)
					{
						green = amount;
					}
				}
				
				inputLine = match.suffix();
			}

			totalPower += (red * blue * green);
		}
	}

	std::cout << totalPower << std::endl;
}
