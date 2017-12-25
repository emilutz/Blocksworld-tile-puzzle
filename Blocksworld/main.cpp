#include "stdio.h"
#include "iostream"
#include "conio.h"
#include "stdlib.h"
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

#include "State.h"
#include "StarState.h"
#include "AStarSearch.h"
#include "BlindSearchAlgorithm.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "IterativeDeepeningSearch.h"


int main()
{
	//====================[ READ INPUT FROM FILE ]====================\\

	std::ifstream f("input_states.txt");

	// read board dimensions
	int rows, cols;
	f >> rows >> cols;

	// allocate memory for matrices
	char** startMatrix = new char*[rows];
	char** goalMatrix = new char*[rows];
	for (int r = 0; r < rows; r++)
	{
		startMatrix[r] = new char[cols];
		goalMatrix[r] = new char[cols];
	}

	// omit header line
	std::string header;
	std::getline(f, header);
	std::getline(f, header);

	// read start state
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			f >> startMatrix[r][c];
		}
	}

	// omit header line
	std::getline(f, header);
	std::getline(f, header);

	// read goal state
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			f >> goalMatrix[r][c];
		}
	}


	std::cout << "States read succesfully" << std::endl;

	//====================[ Choose the type of search ]====================\\

	char mode = 0;
	char command = 0;
	bool graphMode = false;

	std::cout << "---Choose the search algorithm---" << std::endl;
	std::cout << "a for A*" << std::endl;
	std::cout << "b for Breadth First" << std::endl;
	std::cout << "d for Depth First" << std::endl;
	std::cout << "i for Iterative Deepening" << std::endl;

	command = _getch();

	std::cout << "---Choose the mode---" << std::endl;
	std::cout << "t for Tree Search" << std::endl;
	std::cout << "g for Graph Search" << std::endl;

	mode = _getch();
	if (mode == 't')
	{
		graphMode = false;
	}
	else if (mode == 'g')
	{
		graphMode = true;
	}
	else 
	{
		std::cout << "Invalid search mode. Good night !" << std::endl;
		_getch();
		return 0;
	}


	if (command == 'a')
	{
		StarState* goalState  = new StarState(NULL, NULL, rows, cols, goalMatrix);
		StarState* startState = new StarState(NULL, NULL, rows, cols, startMatrix);

		std::cout << std::endl;
		std::cout << "Start state" << std::endl;
		startState->display();
		std::cout << "Goal state" << std::endl;
		goalState->display();

		AStarSearch* searchAlgorithm = new AStarSearch(startState, goalState);

		std::cout << "Are you ready ?" << std::endl;
		_getch();

		std::cout << "I said: ARE YOU REAAAAADYYYYYY ?" << std::endl;
		_getch();

		std::cout << "Pame !" << std::endl;

		try
		{
			auto start = std::chrono::steady_clock::now();
			searchAlgorithm->solve(graphMode);
			auto end   = std::chrono::steady_clock::now();
			std::cout << "Time elapsed : " << 
				std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0
				<< " seconds" << std::endl;
		}
		catch (std::bad_alloc& ba)
		{
			std::cout << "Ran out of memory :(" << std::endl;
		}
	}
	else
	{
		State* goalState = new State(NULL, rows, cols, goalMatrix);
		State* startState = new State(NULL, rows, cols, startMatrix);

		std::cout << std::endl;
		std::cout << "Start state" << std::endl;
		startState->display();
		std::cout << "Goal state" << std::endl;
		goalState->display();

		BlindSearchAlgorithm* searchAlgorithm = NULL;

		char expansionMode = 0;
		bool randomExpansion = false;

		std::cout << "---Random node expansion ?---" << std::endl;
		std::cout << "y for Yes, go crazy !" << std::endl;
		std::cout << "n for No, keep it deterministic ffs..." << std::endl;

		expansionMode = _getch();
		if (expansionMode == 'n')
		{
			randomExpansion = false;
		}
		else if (expansionMode == 'y')
		{
			randomExpansion = true;
		}
		else
		{
			std::cout << "Invalid random expansion answer. Good night !" << std::endl;
			_getch();
			return 0;
		}

		switch (command)
		{
		case 'b':
			searchAlgorithm = new BreadthFirstSearch(startState, goalState, randomExpansion);
			break;
		case 'd':
			searchAlgorithm = new DepthFirstSearch(startState, goalState, randomExpansion);
			break;
		case 'i':
			searchAlgorithm = new IterativeDeepeningSearch(startState, goalState, randomExpansion);
			break;
		default:
			std::cout << "Invalid search algorithm. Good night !" << std::endl;
			_getch();
			return 0;
		}

		std::cout << "Are you ready ?" << std::endl;
		_getch();

		std::cout << "I said: ARE YOU REAAAAADYYYYYY ?" << std::endl;
		_getch();

		std::cout << "Pame !" << std::endl;

		try
		{
			auto start = std::chrono::steady_clock::now();
			searchAlgorithm->solve(graphMode);
			auto end = std::chrono::steady_clock::now();
			std::cout << "Time elapsed : " <<
				std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0
				<< " seconds" << std::endl;
		}
		catch (std::bad_alloc& ba)
		{
			std::cout << "Ran out of memory :(" << std::endl;
		}
	}

	_getch();
	return 0;
}