#pragma once

#include "conio.h"
#include <ctime>
#include <cstdlib>
#include <algorithm> 

#include "State.h"
#define BLIND_EXPANSION_LIMIT 20000000

class BlindSearchAlgorithm
{
protected:
	State* startState;
	State* goalState;
	std::vector<State*> expandStates(State* state, bool randomly, bool graphMode);
	std::vector<State*> visited;
	bool isVisited(State* state);
public:
	BlindSearchAlgorithm(State* s, State* g);
	virtual ~BlindSearchAlgorithm();
	virtual void solve(bool graphMode) = 0;
};