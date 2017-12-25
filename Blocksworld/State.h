#pragma once

#include "stdlib.h"
#include "iostream"
#include <vector>
#include <stack>

#define BLANK 32
#define HERO 254

class State
{
protected:
	int height, width;
	int heroR, heroC;
	char** board;
	State* previousState;
public:
	State(State* father, int height, int width, char** stateMatrix);
	State(State* s);
	~State();
	bool equalTo(const State &s);
	bool equalToStrongly(const State &s);
	void display();
	int printStateTrace();
	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();
};