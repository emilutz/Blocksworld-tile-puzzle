#pragma once

#include "queue"
#include "iostream"

#include "SearchAlgorithm.h"

class BreadthFirstSearch : public SearchAlgorithm
{
public:
	BreadthFirstSearch(State* s, State *g, bool re) : SearchAlgorithm(s, g)
	{
		randomExpansion = re;
		std::cout << "Breadth First Search initialized" << std::endl;
	}
	~BreadthFirstSearch();
	void solve();
private:
	bool randomExpansion;
	std::queue<State*> fringe;
};
