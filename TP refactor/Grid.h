#ifndef Grid_h
#define Grid_h

#include "Cell.h"

class Grid
{
	
public:
	Grid(int line, int column);

private:
	vector<vector<Cell> > gameGrid;
};


#endif