#pragma once
#include "Grid.h"

class Cell
{
public:
	Cell(int Line, int Column, int IsAvailable);
	~Cell();

private:
	int line;
	int column;
	bool isAvailable;
};