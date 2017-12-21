#pragma once

#include "stdlib.h"
#include "iostream"
#include <vector>

#define BLANK 32
#define HERO 254
#define ASCII_OFFSET 65

class State
{
private:
	int height, width;
	int heroR, heroC;
	char** board;
public:
	State(int height, int width, int heroX, int heroY, std::vector<int> blocksX, std::vector<int> blocksY);
	State(const State &s);
	~State();
	bool equalTo(const State &s);
	void display();
	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();
};