#ifndef Grid_h
#define Grid_h

#include "Cell.h"

class Grid
{
public:
	Grid();
	void DisplayGrid();
	Cell GetGrid(int i, int j);

private:
	//ATTENTION IL INITIALISE TOUTE LES CASES
	Cell gameGrid[3][3];
};

#endif
