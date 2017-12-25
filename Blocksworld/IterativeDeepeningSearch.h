#pragma once

#include "iostream"
#include <vector>

#include "BlindSearchAlgorithm.h"

class IterativeDeepeningSearch : public BlindSearchAlgorithm
{
public:
	IterativeDeepeningSearch(State* s, State *g, bool re) : BlindSearchAlgorithm(s, g)
	{
		randomExpansion = re;
		std::cout << "Iterative Deepening Search initialized" << std::endl;
	}
	~IterativeDeepeningSearch();
	void solve(bool graphMode);
private:
	bool randomExpansion;
	std::vector<State*> fringe;
};
