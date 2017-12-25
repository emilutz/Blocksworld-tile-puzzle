#include "StarState.h"

StarState::StarState(StarState* father, StarState* goal, int h, int w, char** stateMatrix) 
	: State(father, h, w, stateMatrix)
{
	if (goal != NULL)
	{
		g = 0;
		h = heuristicDistanceImproved(*goal);
		f = g + h;
	}
}


StarState::StarState(StarState* fatherState, StarState* goalState) : State(fatherState)
{
	g = fatherState->g + 1;
	h = heuristicDistanceImproved(*goalState);
	f = g + h;
}


int StarState::getF()
{
	return f;
}

int StarState::getH()
{
	return h;
}


int StarState::heuristicDistance(StarState &referenceState)
{
	int distance = 0;
	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			if (board[r][c] != referenceState.board[r][c])
			{
				if ((board[r][c] != (char)BLANK && board[r][c] != (char)HERO) ||
					(referenceState.board[r][c] != (char)BLANK && referenceState.board[r][c] != (char)HERO))
				{
					distance++;
				}
			}
		}
	}
	return distance;
}

int StarState::heuristicDistanceImproved(StarState &referenceState)
{
	int distance = 0;
	std::unordered_map<char, int> rowMap;
	std::unordered_map<char, int> colMap;

	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			// check for this state
			if (board[r][c] != (char)BLANK && board[r][c] != (char)HERO)
			{
				// element not in the map yet
				if (rowMap.find(board[r][c]) == rowMap.end())
				{
					rowMap[board[r][c]] = r;
					colMap[board[r][c]] = c;
				}
				else // element already found
				{
					distance += std::abs(r - rowMap[board[r][c]]);
					distance += std::abs(c - colMap[board[r][c]]);
				}
			}

			// check for the reference state
			if (referenceState.board[r][c] != (char)BLANK && referenceState.board[r][c] != (char)HERO)
			{
				// element not in the map yet
				if (rowMap.find(referenceState.board[r][c]) == rowMap.end())
				{
					rowMap[referenceState.board[r][c]] = r;
					colMap[referenceState.board[r][c]] = c;
				}
				else // element already found
				{
					distance += std::abs(r - rowMap[referenceState.board[r][c]]);
					distance += std::abs(c - colMap[referenceState.board[r][c]]);
				}
			}
		}
	}
	return distance;
}
