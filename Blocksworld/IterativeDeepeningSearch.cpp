#include "IterativeDeepeningSearch.h"


IterativeDeepeningSearch::~IterativeDeepeningSearch()
{
	std::cout << "Iterative Deepening Search is over" << std::endl;
}


void IterativeDeepeningSearch::solve(bool graphMode)
{
	// initialize depth limit
	int depthLimit = 0;

	int nodesExpanded = 0;
	int depthReached = 0;
	bool solutionFound = false;
	while (!solutionFound)
	{
		// increase depth limit and reset the fringe
		depthLimit++;
		fringe.clear();
		std::vector<int> nodeDepths;
		int depth = 0;

		// initialize the fringe
		fringe.push_back(startState);
		nodeDepths.push_back(depth);

		// clear visited nodes (for graph mode only)
		visited.clear();
		visited.push_back(startState);

		while (!fringe.empty())
		{
			// pop the next state
			State* currentState = fringe[fringe.size() - 1];
			fringe.pop_back();
			depth = nodeDepths[nodeDepths.size() - 1];
			nodeDepths.pop_back();

			// avoid expanding deeper than the current limit
			if (depth > depthLimit)
			{
				continue;
			}

			//std::cout << "Depth Limit " << depthLimit << std::endl;
			//currentState->display();
			//_getch();

			// verify if goal state reached
			if (currentState->equalTo(*goalState))
			{
				std::cout << "Reached goal stated !" << std::endl;
				std::cout << "State Trace :" << std::endl << std::endl;
				depthReached = currentState->printStateTrace();
				solutionFound = true;
				break;
			}
			nodesExpanded++;

			// expand the current state
			std::vector<State*> newStates = expandStates(currentState, randomExpansion, graphMode);
			for (int i = 0; i < newStates.size(); i++)
			{
				fringe.push_back(newStates[i]);
				nodeDepths.push_back(depth + 1);
			}

			// print state from time to time
			if (nodesExpanded % 10000 == 0)
			{
				std::cout << "Expanded " << nodesExpanded << "... " 
					<< "(Depth Limit : " << depthLimit << ")" << std::endl;
			}

			// expansion limit
			if (nodesExpanded >= BLIND_EXPANSION_LIMIT)
			{
				std::cout << "Expansion limit reached" << std::endl;
				return;
			}
		}
		
	}

	std::cout << "Node expansions : " << nodesExpanded << std::endl;
	std::cout << "Depth reached : " << depthReached << std::endl;
}
