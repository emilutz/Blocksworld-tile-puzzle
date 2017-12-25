#include "BreadthFirstSearch.h"


BreadthFirstSearch::~BreadthFirstSearch()
{
	std::cout << "Breadth First Search is over" << std::endl;
}


void BreadthFirstSearch::solve(bool graphMode)
{
	// initialize the fringe
	fringe.push(startState);

	// clear visited nodes (for graph mode only)
	visited.clear();
	visited.push_back(startState);

	// traverse the tree in DFS way
	int nodesExpanded = 0;
	int depthReached = 0;
	while (true)
	{
		// fringe is somehow empty
		if (fringe.empty())
		{
			std::cout << "No solution found !" << std::endl;
			return;
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
			std::cout << "State Trace :" << std::endl << std::endl;
			depthReached = currentState->printStateTrace();
			break;
		}
		nodesExpanded++;

		// expand the current state
		std::vector<State*> newStates = expandStates(currentState, randomExpansion, graphMode);
		for (int i = 0; i < newStates.size(); i++)
		{
			fringe.push(newStates[i]);
		}

		// print state from time to time
		if (nodesExpanded % 10000 == 0)
		{
			std::cout << "Expanded " << nodesExpanded << "..." << std::endl;
		}

		// expansion limit
		if (nodesExpanded >= BLIND_EXPANSION_LIMIT)
		{
			std::cout << "Expansion limit reached" << std::endl;
			return;
		}
	}

	std::cout << "Node expansions : " << nodesExpanded << std::endl;
	std::cout << "Depth reached : " << depthReached << std::endl;
}
