#include "Grid.h"

Grid::Grid(int line, int column) {

	gameGrid.resize(line);

	for (int k = 0; k < line; k++) {
		gameGrid[k].resize(column);
	}
	Cell::SetIdStatic(1);
}