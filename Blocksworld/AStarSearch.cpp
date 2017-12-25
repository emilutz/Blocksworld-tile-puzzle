#include "AStarSearch.h"

AStarSearch::AStarSearch(StarState* s, StarState* g)
{
	std::cout << "A* Search initialized" << std::endl;

	startState = s;
	goalState = g;
}

AStarSearch::~AStarSearch()
{
	std::cout << "A* Search is over" << std::endl;
}


std::vector<StarState*> AStarSearch::expandStates(StarState* state, StarState* goal, bool graphMode)
{
	// assign the expanded states in a vector
	std::vector<StarState*> newStates;
	for (int i = 0; i < 4; i++)
	{
		StarState* newState = new StarState(state, goal);
		bool canMove = false;

		switch (i)
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
			if (graphMode)
			{
				if (!isVisited(newState))
				{
					newStates.push_back(newState);
					visited.push_back(newState);
				}
			}
			else
			{
				newStates.push_back(newState);
			}
		}
	}

	return newStates;
}

bool AStarSearch::isVisited(StarState* state)
{
	for (int i = 0; i < visited.size(); i++)
	{
		if (state->equalToStrongly(*visited[i]))
		{
			return true;
		}
	}
	return false;
}


void AStarSearch::solve(bool graphMode)
{
	// initialize the fringe
	fringe.push(startState);

	// clear visited nodes (for graph mode only)
	visited.clear();
	visited.push_back(startState);

	// search the space until reaching the goal state
	int nodesExpanded = 0;
	int depthReached = 0;
	while (true)
	{
		// fringe is somehow empty
		if (fringe.empty())
		{
			std::cout << "No solution found !" << std::endl;
			break;
		}

		// pop the next state
		StarState* currentState = fringe.top();
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
		std::vector<StarState*> newStates = expandStates(currentState, goalState, graphMode);
		for (int i = 0; i < newStates.size(); i++)
		{
			fringe.push(newStates[i]);
		}

		// print state from time to time
		if (nodesExpanded % 1000 == 0)
		{
			std::cout << "Expanded " << nodesExpanded << "... " << std::endl;
		}

		// expansion limit
		if (nodesExpanded >= STAR_EXPANSION_LIMIT)
		{
			std::cout << "Expansion limit reached" << std::endl;
			return;
		}
	}

	std::cout << "Node expansions : " << nodesExpanded << std::endl;
	std::cout << "Depth reached : " << depthReached << std::endl;
}
