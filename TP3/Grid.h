#pragma once
#include "Game.h"
#include "Cell.h"

class Grid
{
public:
	Grid();
	~Grid();
	void InitGrid();

private:
	Cell gameGrid[3][3];
};
