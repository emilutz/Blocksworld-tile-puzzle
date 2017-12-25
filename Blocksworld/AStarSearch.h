#pragma once

#include "conio.h"
#include "iostream"
#include <queue>
#include <ctime>
#include <cstdlib>
#include <algorithm> 

#include "StarState.h"

#define STAR_EXPANSION_LIMIT 3000000

class AStarCompare
{
public:
	bool operator() (StarState* s1, StarState* s2)
	{
		if (s1->getF() > s2->getF())
		{
			return true;
		}
		else if (s1->getF() == s2->getF())
		{
			return (s1->getH() > s2->getH());
		}
		return false;
	}
};


class AStarSearch 
{
private:
	StarState* startState;
	StarState* goalState;
	std::priority_queue<StarState*, std::vector<StarState*>, AStarCompare> fringe;
	std::vector<StarState*> expandStates(StarState* state, StarState* goal, bool graphMode);
	std::vector<StarState*> visited;
	bool isVisited(StarState* state);
public:
	AStarSearch(StarState* s, StarState *g);
	~AStarSearch();
	void solve(bool graphMode);
};
