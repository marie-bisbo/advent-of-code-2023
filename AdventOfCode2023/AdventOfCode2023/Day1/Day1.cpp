#include "Day1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <map>
#include <regex>
#include <filesystem>

void Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day1/Day1Input.txt");
	std::string inputLine;

	int totalCalibrationValue = 0;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);
			char first = '0';
			char second = '0';

			for (int i = 0; i < inputLine.length(); i++)
			{
				if (isdigit(inputLine[i]))
				{
					first = inputLine[i];
					break;
				}
			}

			for (int j = inputLine.length(); j >= 0; j--)
			{
				if (isdigit(inputLine[j]))
				{
					second = inputLine[j];
					break;
				}
			}

			std::string calibrationValue{ first, second };

			totalCalibrationValue += std::stoi(calibrationValue);
		}
	}

	std::cout << totalCalibrationValue << std::endl;
}

void Puzzle2()
{
	std::map<std::string, int> wordToNumber;
	wordToNumber["zero"] = '0';
	wordToNumber["one"] = '1';
	wordToNumber["two"] = '2';
	wordToNumber["three"] = '3';
	wordToNumber["four"] = '4';
	wordToNumber["five"] = '5';
	wordToNumber["six"] = '6';
	wordToNumber["seven"] = '7';
	wordToNumber["eight"] = '8';
	wordToNumber["nine"] = '9';

	std::fstream input;
	input.open("../AdventOfCode2023/Day1/Day1Input.txt");
	std::string inputLine;

	int totalCalibrationValue = 0;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			std::regex regexpr("zero|one|two|three|four|five|six|seven|eight|nine|[0-9]");
			std::vector<char> matches;
			std::string temp;
			for (std::smatch match; std::regex_search(inputLine, match, regexpr);)
			{
				temp = inputLine[match.position() + match.str().length() - 1] + match.suffix().str();
				char matchAsNumber = isdigit(match.str()[0]) ? match.str()[0] : wordToNumber[match.str()];
				matches.push_back(matchAsNumber);
				inputLine = match.suffix();
			}

			char end = matches.back();
			for (const auto& word : wordToNumber)
			{
				if (temp.find(word.first) != std::string::npos)
				{
					end = word.second;
				}
			}
			
			std::string calibrationValue{ matches[0], end };

			totalCalibrationValue += std::stoi(calibrationValue);
		}
	}

	std::cout << totalCalibrationValue << std::endl;
}