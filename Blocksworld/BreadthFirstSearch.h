#pragma once

#include "iostream"
#include <queue>

#include "BlindSearchAlgorithm.h"

class BreadthFirstSearch : public BlindSearchAlgorithm
{
public:
	BreadthFirstSearch(State* s, State *g, bool re) : BlindSearchAlgorithm(s, g)
	{
		randomExpansion = re;
		std::cout << "Breadth First Search initialized" << std::endl;
	}
	~BreadthFirstSearch();
	void solve(bool graphMode);
private:
	bool randomExpansion;
	std::queue<State*> fringe;
};
