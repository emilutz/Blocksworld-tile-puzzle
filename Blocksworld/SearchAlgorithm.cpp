#include "SearchAlgorithm.h"

SearchAlgorithm::SearchAlgorithm(State* s, State* g)
{
	startState = s;
	goalState = g;
}

SearchAlgorithm::~SearchAlgorithm()
{
	delete startState;
	delete goalState;
}


int myrandom(int i) 
{
	return std::rand() % i; 
}

std::vector<State*> SearchAlgorithm::expandStates(State * state, bool randomly)
{
	// create indexes for the directions of hero movement
	std::vector<int> indexes;
	for (int i = 0; i < 4; i++)
	{
		indexes.push_back(i);
	}

	// randomize in case the order of the next states is random
	if (randomly)
	{
		std::srand(unsigned(std::time(0)));
		std::random_shuffle(indexes.begin(), indexes.end(), myrandom);
	}

	// assign the expanded states in a vector
	std::vector<State*> newStates;
	for (int i = 0; i < 4; i++)
	{
		State* newState = new State(*state);
		bool canMove = false;

		switch (indexes[i])
		{
		case 0:
			canMove = newState->moveUp();
			break;
		case 1:
			canMove = newState->moveRight();
			break;
		case 2:
			canMove = newState->moveDown();
			break;
		default:
			canMove = newState->moveLeft();
		}
		if (canMove)
		{
			newStates.push_back(newState);
		}
	}

	return newStates;
}
