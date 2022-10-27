#pragma once
#include "Grid.h"

class Cell
{
public:
	Cell(const int& Line, const int& Column, const int& Owner);
	Cell();

private:
	int line;
	int column;
	//0 = free; 1 = player 1; 2 = player 2
	int owner;
};