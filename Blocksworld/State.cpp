#include "State.h"


State::State(State* father, int h, int w, char** stateMatrix)
{
	// set local variables
	height = h;
	width = w;
	previousState = father;

	// allocate memory for the board
	board = new char*[height];
	for (int r = 0; r < height; r++)
	{
		board[r] = new char[width];
	}

	// construct the board from the input matrix
	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			switch (stateMatrix[r][c])
			{
			case '0':
				board[r][c] = BLANK;
				break;
			case '*':
				board[r][c] = HERO;
				heroR = r;
				heroC = c;
				break;
			default:
				board[r][c] = stateMatrix[r][c];
				break;
			}
		}
	}

}

State::State(State* s)
{
	// set local variables
	height = s->height;
	width = s->width;
	heroR = s->heroR;
	heroC = s->heroC;
	previousState = s;

	// allocate memory for the board
	board = new char*[height];
	for (int r = 0; r < height; r++)
	{
		board[r] = new char[width];
	}

	// initialize the board elements
	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			board[r][c] = s->board[r][c];
		}
	}
}

State::~State()
{
	for (int r = 0; r < height; r++)
	{
		delete[] board[r];
	}
	delete[] board;
}


// print the sequence of states from the start until the goal
int State::printStateTrace()
{
	std::stack<State*> trace;
	State* currentState = this;

	// stack the states backwards
	while (currentState != NULL)
	{
		trace.push(currentState);
		currentState = currentState->previousState;
	}

	int depth = trace.size() - 1;

	// display the states in their original order
	while (!trace.empty())
	{
		trace.top()->display();
		trace.pop();
	}

	return depth;
}

// check equality between states
bool State::equalTo(const State &s)
{
	// test dimensions
	if (height != s.height || width != s.width)
	{
		return false;
	}

	// test board contents
	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			if (board[r][c] != s.board[r][c])
			{
				if((board[r][c] != (char)BLANK && board[r][c] != (char)HERO) ||
					(s.board[r][c] != (char)BLANK && s.board[r][c] != (char)HERO))
				{ 
					return false;
				}
			}
		}
	}
	
	return true;
}


// check strong equality between states
bool State::equalToStrongly(const State &s)
{
	// test dimensions
	if (height != s.height || width != s.width)
	{
		return false;
	}

	// test board contents
	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			if (board[r][c] != s.board[r][c])
			{
				return false;
			}
		}
	}

	return true;
}

// display a visualization of the current state
void State::display()
{
	std::cout << std::endl << "   ";

	// upper part
	std::cout << (char)201;
	for (int c = 0; c < width - 1; c++)
	{
		std::cout << (char)205 << (char)203;
	}
	std::cout << (char)205 << (char)187 << std::endl << "   ";

	// middle
	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			std::cout << (char)186 << board[r][c];
		}
		std::cout << (char)186 << std::endl << "   ";

		if (r < height - 1)
		{
			std::cout << (char)204;
			for (int c = 0; c < width - 1; c++)
			{
				std::cout << (char)205 << (char)206;
			}
			std::cout << (char)205 << (char)185 << std::endl << "   ";
		}
	}

	// lower part
	std::cout << (char)200;
	for (int c = 0; c < width - 1; c++)
	{
		std::cout << (char)205 << (char)202;
	}
	std::cout << (char)205 << (char)188 << std::endl << std::endl;
}


bool State::moveUp()
{
	if (heroR > 0)
	{
		char swapper = board[heroR][heroC];
		board[heroR][heroC] = board[heroR - 1][heroC];
		board[heroR - 1][heroC] = swapper;
		heroR--;
		return true;
	}
	else
	{
		return false;
	}
}

bool State::moveDown()
{
	if (heroR < height - 1)
	{
		char swapper = board[heroR][heroC];
		board[heroR][heroC] = board[heroR + 1][heroC];
		board[heroR + 1][heroC] = swapper;
		heroR++;
		return true;
	}
	else
	{
		return false;
	}
}

bool State::moveLeft()
{
	if (heroC > 0)
	{
		char swapper = board[heroR][heroC];
		board[heroR][heroC] = board[heroR][heroC - 1];
		board[heroR][heroC - 1] = swapper;
		heroC--;
		return true;
	}
	else
	{
		return false;
	}
}

bool State::moveRight()
{
	if (heroC < width - 1)
	{
		char swapper = board[heroR][heroC];
		board[heroR][heroC] = board[heroR][heroC + 1];
		board[heroR][heroC + 1] = swapper;
		heroC++;
		return true;
	}
	else
	{
		return false;
	}
}
