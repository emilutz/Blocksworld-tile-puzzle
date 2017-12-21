#pragma once

#include "stdlib.h"
#include "iostream"
#include <vector>
#include <stack>

#define BLANK 32
#define HERO 254
#define ASCII_OFFSET 65

class State
{
private:
	int height, width;
	int heroR, heroC;
	char** board;
	State* previousState;
public:
	State(State* father, int height, int width, int heroX, int heroY, std::vector<int> blocksX, std::vector<int> blocksY);
	State(State* s);
	~State();
	bool equalTo(const State &s);
	void display();
	int printStateTrace();
	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();
};