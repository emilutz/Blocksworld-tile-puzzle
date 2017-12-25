#pragma once

#include "iostream"
#include <stack>

#include "BlindSearchAlgorithm.h"

class DepthFirstSearch : public BlindSearchAlgorithm 
{
public:
	DepthFirstSearch(State* s, State *g, bool re) : BlindSearchAlgorithm(s, g)
	{
		randomExpansion = re;
		std::cout << "Depth First Search initialized" << std::endl;
	}
	~DepthFirstSearch();
	void solve(bool graphMode);
private:
	bool randomExpansion;
	std::stack<State*> fringe;
};
