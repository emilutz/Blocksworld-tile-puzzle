#include "stdio.h"
#include "iostream"
#include "conio.h"
#include "stdlib.h"

#include "State.h"


int main()
{
	std::vector<int> blocksR = { 3, 3, 3 };
	std::vector<int> blocksC = { 0, 1, 2 };

	State* state = new State(4, 4, 2, 2, blocksR, blocksC);

	State* d = new State(*state);

	state->display();

	d->moveRight();

	d->display();

	_getch();
	return 0;
}