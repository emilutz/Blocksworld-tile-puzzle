#pragma once

#include "conio.h"
#include <ctime>
#include <cstdlib>
#include <algorithm> 

#include "State.h"

class SearchAlgorithm
{
protected:
	State* startState;
	State* goalState;
	std::vector<State*> expandStates(State* state, bool randomly);
public:
	SearchAlgorithm(State* s, State* g);
	virtual ~SearchAlgorithm();
	virtual void solve() = 0;
};