#include "Day17.h"
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

constexpr int GRID_SIZE = 13;

// Use breadth first search algorithm! Use queue or deque
struct Node
{
	int heatLoss = 0;
	bool visited = false;
	Direction direction = Direction::Right;
};

void Day17Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day17/Day17Input.txt");
	std::string inputLine;

	std::vector<char> elements;
	std::vector<Node> nodes(GRID_SIZE * GRID_SIZE, Node{});

	if (input.is_open())
	{
		int currentPosition = 0;
		while (!input.eof())
		{
			std::getline(input, inputLine);

			for (const char c : inputLine)
			{
				nodes[currentPosition].heatLoss = c - '0';
				currentPosition++;
			}
		}
	}

	std::list<int> queue;
	nodes[0].visited = true;
	int currentNode = 0;
	queue.push_back(currentNode);

	while (!queue.empty())
	{
		currentNode = queue.front();
		std::cout << currentNode << std::endl;
		queue.pop_front();

		for (const auto adjacent : GetAdjacentNodes(currentNode, nodes))
		{
			if (!nodes[adjacent].visited)
			{
				nodes[adjacent].visited = true;
				queue.push_back(adjacent);
			}
		}
	}
}

void Day17Puzzle2()
{
}

std::vector<int> GetAdjacentNodes(int node, const std::vector<Node>& nodes)
{
	std::vector<int> adjacentNodes;

	if ((node + 1) % GRID_SIZE != 0 && (node + 1) < GRID_SIZE * GRID_SIZE)
	{
		adjacentNodes.push_back(node + 1);
	}
	if (node % GRID_SIZE != 0 && (node - 1) > -1)
	{
		adjacentNodes.push_back(node - 1);
	}
	if ((node + GRID_SIZE) < GRID_SIZE * GRID_SIZE)
	{
		adjacentNodes.push_back(node + GRID_SIZE);
	}
	if ((node - GRID_SIZE) > -1)
	{
		adjacentNodes.push_back(node - GRID_SIZE);
	}

	return adjacentNodes;
}

