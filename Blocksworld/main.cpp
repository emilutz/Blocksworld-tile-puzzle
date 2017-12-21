#include "stdio.h"
#include "iostream"
#include "conio.h"
#include "stdlib.h"

#include "State.h"
#include "SearchAlgorithm.h"
#include "DepthFirstSearch.h"


int main()
{
	std::vector<int> blocksRstart = { 3, 3, 3 };
	std::vector<int> blocksCstart = { 0, 1, 2 };
	State* startState = new State(4, 4, 3, 3, blocksRstart, blocksCstart);

	std::cout << "Start state" << std::endl;
	startState->display();

	std::vector<int> blocksRgoal = { 1, 2, 3 };
	std::vector<int> blocksCgoal = { 1, 1, 1 };
	State* goalState = new State(4, 4, 3, 2, blocksRgoal, blocksCgoal);

	std::cout << "Goal state" << std::endl;
	goalState->display();

	DepthFirstSearch* searchAlgorithm = new DepthFirstSearch(startState, goalState, true);

	try
	{
		searchAlgorithm->solve();
	}
	catch (std::bad_alloc& ba)
	{
		std::cout << "Ran out of memory :(" << std::endl;
	}

	_getch();
	return 0;
}