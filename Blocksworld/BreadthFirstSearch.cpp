#include "BreadthFirstSearch.h"


BreadthFirstSearch::~BreadthFirstSearch()
{
	std::cout << "Breadth First Search is over" << std::endl;
}


void BreadthFirstSearch::solve()
{
	// initialize the fringe
	fringe.push(startState);

	// traverse the tree in DFS way
	int nodesExpanded = 0;
	while (true)
	{
		// fringe is somwhow empty
		if (fringe.empty())
		{
			std::cout << "No solution found !" << std::endl;
			break;
		}

		// pop the next state
		State* currentState = fringe.front();
		fringe.pop();

		//currentState->display();
		//_getch();

		// verify if goal state reached
		if (currentState->equalTo(*goalState))
		{
			std::cout << "Reached goal stated !" << std::endl;
			break;
		}
		nodesExpanded++;

		// expand the current state
		std::vector<State*> newStates = expandStates(currentState, randomExpansion);
		for (int i = 0; i < newStates.size(); i++)
		{
			fringe.push(newStates[i]);
		}

		// release the current state from memory
		delete currentState;

		if (nodesExpanded % 10000 == 0)
		{
			std::cout << "Expanded " << nodesExpanded << "..." << std::endl;
		}
	}

	std::cout << "Node expansions : " << nodesExpanded << std::endl;
}
