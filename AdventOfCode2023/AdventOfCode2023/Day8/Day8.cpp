#include "Day8.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <math.h>
#include <map>
#include <unordered_set>

struct Node
{
	std::string current;
	std::string left;
	std::string right;
};

void Day8Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day8/Day8Input.txt");
	std::string inputLine;

	std::vector<Node> nodes;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			Node node{ inputLine.substr(0, 3), inputLine.substr(7, 3), inputLine.substr(12, 3) };
			nodes.push_back(node);
		}
	}

	char instructions[307] = { 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'L', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'L', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'L', 'R', 'R', 'R', 'L', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'L', 'L', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'R' };

	std::string current = "";
	Node currentNode = nodes[685];
	int numSteps = 0;
	while (current != "ZZZ")
	{
		for (int instruction = 0; instruction < 307; instruction++)
		{
			if (instructions[instruction] == 'L')
			{
				current = currentNode.left;
			}
			else if (instructions[instruction] == 'R')
			{
				current = currentNode.right;
			}

			numSteps++;

			if (current == "ZZZ")
			{
				break;
			}

			for (const auto node : nodes)
			{
				if (node.current == current)
				{
					currentNode = node;
				}
			}
		}
	}

	std::cout << numSteps << std::endl;
}

void Day8Puzzle2()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day8/Day8Input.txt");
	std::string inputLine;

	std::vector<Node> nodes;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			Node node{ inputLine.substr(0, 3), inputLine.substr(7, 3), inputLine.substr(12, 3) };
			nodes.push_back(node);
		}
	}

	char instructions[307] = { 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'L', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'L', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'L', 'R', 'R', 'R', 'L', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'L', 'L', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'R', 'R', 'R', 'R' };
	// Manually identified the values ending in A
	int nodesToCheck[6] = {16, 69, 107, 150, 346, 685};

	Node currentNode = nodes[nodesToCheck[5]];
	std::string current = currentNode.current;
	int numSteps = 0;
	while (current[2] != 'Z')
	{
		for (int instruction = 0; instruction < 307; instruction++)
		{
			if (instructions[instruction] == 'L')
			{
				current = currentNode.left;
			}
			else if (instructions[instruction] == 'R')
			{
				current = currentNode.right;
			}

			numSteps++;

			if (current[2] =='Z')
			{
				break;
			}

			for (const auto node : nodes)
			{
				if (node.current == current)
				{
					currentNode = node;
				}
			}
		}
	}

	// Manually ran the code 6 times, once for each path, and plonked them in an online lcm calculator. Can this be done in code? Yes. Did I do that? No
	std::cout << numSteps << std::endl;
}
