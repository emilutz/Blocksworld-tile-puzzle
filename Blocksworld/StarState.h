#pragma once
#include <unordered_map>

#include "State.h"

class StarState : public State
{
private:
	int f, g, h;
	int heuristicDistance(StarState &referenceState);
	int heuristicDistanceImproved(StarState &referenceState);
public:
	StarState(StarState* father, StarState* goal, int height, int width, char** stateMatrix);
	StarState(StarState* fatherState, StarState* goalState);
	int getF();
	int getH();
};
