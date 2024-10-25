#pragma once
#include <vector>

struct Node;

enum class Direction
{
	Up,
	Right,
	Down,
	Left
};

void Day17Puzzle1();
void Day17Puzzle2();

std::vector<int> GetAdjacentNodes(int node, const std::vector<Node>& nodes);
