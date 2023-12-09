#include "Day7.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <math.h>
#include <map>
#include <unordered_set>

struct Bid
{
	int hand = 0;
	std::string cards = "";
	int bid = 0;
};

std::map<char, int> cardToValue{ {'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'T', 10} };

void Day7Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day7/Day7Input.txt");
	std::string inputLine;

	std::vector<Bid> bids;

	if (input.is_open())
	{
		while (!input.eof())
		{
			std::getline(input, inputLine);

			std::string cards = inputLine.substr(0, 5);
			int bidValue = std::stoi(inputLine.substr(6));
			int hand = (int)identifyHand(cards);
			Bid bid{ hand, cards, bidValue };

			auto insertIndex = std::upper_bound(bids.begin(), bids.end(), bid, [](const Bid& A, const Bid& B) {
				if (A.hand != B.hand)
				{
					return A.hand < B.hand; 
				}
				for (int i = 0; i < 5; i++)
				{
					if (A.cards[i] != B.cards[i])
					{
						int a = 0;
						if (cardToValue.contains(A.cards[i]))
						{
							a = cardToValue[A.cards[i]];
						}
						else
						{
							a = A.cards[i] - '0';
						}

						int b = 0;
						if (cardToValue.contains(B.cards[i]))
						{
							b = cardToValue[B.cards[i]];
						}
						else
						{
							b = B.cards[i] - '0';
						}

						return a < b;
					}
				}
				});

			bids.insert(insertIndex, bid);
		}
	}

	long totalWinnings = 0;

	for (int bid = 0; bid < bids.size(); bid++)
	{
		totalWinnings += (bid + 1) * bids[bid].bid;
	}

	std::cout << totalWinnings << std::endl;
}

void Day7Puzzle2()
{
}

Hand identifyHand(const std::string& cards)
{
	std::unordered_set<char> uniqueCards;
	for (int c = 0; c < cards.length(); c++)
	{
		uniqueCards.emplace(cards[c]);
	}

	if (uniqueCards.size() == 1)
	{
		return Hand::fiveOfAKind;
	}

	if (std::count(cards.begin(), cards.end(), cards[0]) == 4 || std::count(cards.begin(), cards.end(), cards[1]) == 4)

	{
		return Hand::fourOfAKind;
	}

	if (uniqueCards.size() == 2)
	{
		return Hand::fullHouse;
	}

	if (std::count(cards.begin(), cards.end(), cards[0]) == 3 || std::count(cards.begin(), cards.end(), cards[1]) == 3 || std::count(cards.begin(), cards.end(), cards[2]) == 3)
	{
		return Hand::threeOfAKind;
	}

	if (uniqueCards.size() == 3)
	{
		return Hand::twoPair;
	}

	if (uniqueCards.size() == 4)
	{
		return Hand::onePair;
	}

	return Hand::highCard;
}
