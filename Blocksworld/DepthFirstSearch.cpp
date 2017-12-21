#include "DepthFirstSearch.h"


DepthFirstSearch::~DepthFirstSearch()
{
	std::cout << "Depth First Search is over" << std::endl;
}


void DepthFirstSearch::solve()
{
	// initialize the fringe
	fringe.push(startState);

	// traverse the tree in DFS way
	int nodesExpanded = 0;
	int depthReached = 0;
	while (true)
	{
		// fringe is somwhow empty
		if (fringe.empty())
		{
			std::cout << "No solution found !" << std::endl;
			break;
		}

		// pop the next state
		State* currentState = fringe.top();
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
		std::vector<State*> newStates = expandStates(currentState, randomExpansion);
		for (int i = 0; i < newStates.size(); i++)
		{
			fringe.push(newStates[i]);
		}

		// print state from time to time
		if (nodesExpanded % 10000 == 0)
		{
			std::cout << "Expanded " << nodesExpanded << "..." << std::endl;
		}
	}

	std::cout << "Node expansions : " << nodesExpanded << std::endl;
	std::cout << "Depth reached : " << depthReached << std::endl;
}
