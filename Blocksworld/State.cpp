#include "State.h"


State::State(int h, int w, int hR, int hC, std::vector<int> blocksR, std::vector<int> blocksC)
{
	// set local variables
	height = h;
	width = w;
	heroR = hR;
	heroC = hC;

	// allocate memory for the board
	board = new char*[height];
	for (int r = 0; r < height; r++)
	{
		board[r] = new char[width];
	}

	// initialize the board with empty spots
	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			board[r][c] = BLANK;
		}
	}

	// assign the hero and the blocks positions
	board[heroR][heroC] = HERO;
	for (int i = 0; i < blocksR.size(); i++)
	{
		board[blocksR.at(i)][blocksC.at(i)] = i + ASCII_OFFSET;
	}
}

State::State(const State &s)
{
	// set local variables
	height = s.height;
	width = s.width;
	heroR = s.heroR;
	heroC = s.heroC;

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
			board[r][c] = s.board[r][c];
		}
	}
}


// check equality between states
bool State::equal_to(const State & s)
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


void State::moveUp()
{
	if (heroR > 0)
	{
		char swapper = board[heroR][heroC];
		board[heroR][heroC] = board[heroR - 1][heroC];
		board[heroR - 1][heroC] = swapper;
		heroR--;
	}
}

void State::moveDown()
{
	if (heroR < height - 1)
	{
		char swapper = board[heroR][heroC];
		board[heroR][heroC] = board[heroR + 1][heroC];
		board[heroR + 1][heroC] = swapper;
		heroR++;
	}
}

void State::moveLeft()
{
	if (heroC > 0)
	{
		char swapper = board[heroR][heroC];
		board[heroR][heroC] = board[heroR][heroC - 1];
		board[heroR][heroC - 1] = swapper;
		heroC--;
	}
}

void State::moveRight()
{
	if (heroC < width - 1)
	{
		char swapper = board[heroR][heroC];
		board[heroR][heroC] = board[heroR][heroC + 1];
		board[heroR][heroC + 1] = swapper;
		heroC++;
	}
}
