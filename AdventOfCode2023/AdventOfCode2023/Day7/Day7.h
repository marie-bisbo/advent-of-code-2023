#pragma once

#include <string>

enum class Hand
{
	highCard,
	onePair,
	twoPair,
	threeOfAKind,
	fullHouse,
	fourOfAKind,
	fiveOfAKind
};

void Day7Puzzle1();
void Day7Puzzle2();

Hand identifyHand(const std::string& cards);

