#pragma once

#include "iostream"
#include <stack>

#include "SearchAlgorithm.h"

class DepthFirstSearch : public SearchAlgorithm 
{
public:
	DepthFirstSearch(State* s, State *g, bool re) : SearchAlgorithm(s, g)
	{
		randomExpansion = re;
		std::cout << "Depth First Search initialized" << std::endl;
	}
	~DepthFirstSearch();
	void solve();
private:
	bool randomExpansion;
	std::stack<State*> fringe;
};
