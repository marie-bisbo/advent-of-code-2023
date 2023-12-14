#include "Day13.h"
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

void Day13Puzzle1()
{
	std::fstream input;
	input.open("../AdventOfCode2023/Day13/Day13Input.txt");
	std::string inputLine;
	int totalRowsBefore = 0;
	int totalColumnsBefore = 0;
	int rowCounter = 0;
	if (input.is_open())
	{
		std::vector<std::string> rows;
		int rowsBefore = 0;
		int columnsBefore = 0;
		while (!input.eof())
		{
			rowCounter++; 

			std::getline(input, inputLine);

			if (!inputLine.empty())
			{
				rows.push_back(inputLine);
			}

			if (inputLine.empty() || rowCounter == 1301)
			{
				if (rows.size() == 0)
				{
					break;
				}

				int numColumns = rows[0].length();
				std::vector<std::string> columns(numColumns, "");
				for (int i = 0; i < numColumns; i++)
				{
					for (const auto row : rows)
					{
						columns[i] += row[i];
					}
				}

				bool hasRows = true;
				bool hasColumns = true;

				for (int row = 0; row < rows.size() - 1; row++)
				{
					if (rows[row] == rows[row + 1])
					{
						int toCheck = fmin(row, rows.size() - row - 2);
						int j = row + toCheck + 1;
						hasRows = true;
						for (int i = row - toCheck; i < row; i++)
						{
							if (rows[i] != rows[j])
							{
								hasRows = false;
								break;
							}
							j--;
						}
						if (hasRows)
						{
							rowsBefore = row + 1;
						}
					}
				}

				for (int column = 0; column < columns.size() - 1; column++)
				{
					if (columns[column] == columns[column + 1])
					{
						int toCheck = fmin(column, columns.size() - column - 2);
						int j = column + toCheck + 1;
						hasColumns = true;
						for (int i = column - toCheck; i < column; i++)
						{
							if (columns[i] != columns[j])
							{
								hasColumns = false;
								break;
							}
							j--;
						}
						if (hasColumns)
						{
							columnsBefore = column + 1;
						}
					}
				}

				rows.clear();
				columns.clear();
				totalColumnsBefore += columnsBefore;
				totalRowsBefore += (rowsBefore * 100);
				rowsBefore = 0;
				columnsBefore = 0;
				hasRows = true;
				hasColumns = true;
			}
		}
	}

	std::cout << totalColumnsBefore + totalRowsBefore << std::endl;
}

void Day13Puzzle2()
{
}
