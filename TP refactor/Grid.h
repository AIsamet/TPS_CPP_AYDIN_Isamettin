#ifndef Grid_h
#define Grid_h

#include "Cell.h"

class Grid
{
	
public:
	Grid();
	Grid(int line, int column);
	
	vector<vector<Cell>> GetGameGrid() const { return gameGrid; }
	vector<vector<Cell>>& GetGameGridByReference() { return gameGrid; }

	Cell& GetCellPositionFromId(const int& idCell); //permet de retourner une Cell a partir de son idCell
	
	void DisplayGridMorpion() const;
	void DisplayGridPuissance4() const;


private:
	vector<vector<Cell>> gameGrid;
};


#endif