#include "Grid.h"

Grid::Grid() {
}

Cell Grid::GetGrid(int i, int j) {
	return gameGrid[i][j];
}


void Grid::DisplayGrid() {
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << gameGrid[0][0].DisplayCell() << "  |  " << gameGrid[0][1].DisplayCell() << "  |  " << gameGrid[0][2].DisplayCell() << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << gameGrid[1][0].DisplayCell() << "  |  " << gameGrid[1][1].DisplayCell() << "  |  " << gameGrid[1][2].DisplayCell() << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << gameGrid[2][0].DisplayCell() << "  |  " << gameGrid[2][1].DisplayCell() << "  |  " << gameGrid[2][2].DisplayCell() << endl;

    cout << "     |     |     " << endl << endl;
	cout << "Dans quelle case voulez-vous jouer ?" << endl;
}
