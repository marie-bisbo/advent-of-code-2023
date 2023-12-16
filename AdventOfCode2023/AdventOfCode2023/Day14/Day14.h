#pragma once
#include <vector>

void Day14Puzzle1();
void Day14Puzzle2();

void TiltNorth(std::vector<char>& elements);
void TiltSouth(std::vector<char>& elements);
void TiltWest(std::vector<char>& elements);
void TiltEast(std::vector<char>& elements);

bool CompareElements(const std::vector<char>& first, const std::vector<char>& second);
