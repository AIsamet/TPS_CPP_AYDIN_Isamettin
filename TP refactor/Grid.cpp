#include "Grid.h"

/**
 * @brief   Construit une nouvelle grille
 * @params  line : nombre de lignes, column : nombre de colonnes
**/
Grid::Grid()
{
}
Grid::Grid(int line, int column) {

	gameGrid.resize(line);

	for (int k = 0; k < line; k++) {
		gameGrid[k].resize(column);
	}
	Cell::SetIdStatic(1);
}

/**
 * @brief   Retourne une case a partir de son id
 * @params  idCell : id de la case
 * @return  la case si elle est trouvée, une case vide sinon
**/
Cell& Grid::GetCellPositionFromId(const int& idCell) {
	switch (idCell) {
	case 0:
		return gameGrid[0][0];
	case 1:
		return gameGrid[0][1];
	case 2:
		return gameGrid[0][2];
	case 3:
		return gameGrid[1][0];
	case 4:
		return gameGrid[1][1];
	case 5:
		return gameGrid[1][2];
	case 6:
		return gameGrid[2][0];
	case 7:
		return gameGrid[2][1];
	case 8:
		return gameGrid[2][2];
	}
}

/**
 * @brief   Affiche la grille de jeu (morpion)
 * @return  void
**/
void Grid::DisplayGridMorpion() const {
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << gameGrid[0][0].DisplayCellMorpion() << "  |  " << gameGrid[0][1].DisplayCellMorpion() << "  |  " << gameGrid[0][2].DisplayCellMorpion() << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << gameGrid[1][0].DisplayCellMorpion() << "  |  " << gameGrid[1][1].DisplayCellMorpion() << "  |  " << gameGrid[1][2].DisplayCellMorpion() << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << gameGrid[2][0].DisplayCellMorpion() << "  |  " << gameGrid[2][1].DisplayCellMorpion() << "  |  " << gameGrid[2][2].DisplayCellMorpion() << endl;

	cout << "     |     |     " << endl << endl;
}

/**
 * @brief   Affiche la grille de jeu (puissance 4)
 * @return  void
**/
void Grid::DisplayGridPuissance4() const {
	cout << endl;

	cout << "|  " << "1" << "  |  " << "2" << "  |  " << "3" << "  |  " << "4" << "  |  " << "5" << "  |  " << "6" << "  |  " << "7" << "  |  " << endl;


	cout << " _________________________________________" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;
	cout << "|  " << gameGrid[3][0].DisplayCellPuissance4() << "  |  " << gameGrid[3][1].DisplayCellPuissance4() << "  |  " << gameGrid[3][2].DisplayCellPuissance4() << "  |  " << gameGrid[3][3].DisplayCellPuissance4() << "  |  " << gameGrid[3][4].DisplayCellPuissance4() << "  |  " << gameGrid[3][5].DisplayCellPuissance4() << "  |  " << gameGrid[3][6].DisplayCellPuissance4() << "  |  " << endl;

	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;

	cout << "|  " << gameGrid[2][0].DisplayCellPuissance4() << "  |  " << gameGrid[2][1].DisplayCellPuissance4() << "  |  " << gameGrid[2][2].DisplayCellPuissance4() << "  |  " << gameGrid[2][3].DisplayCellPuissance4() << "  |  " << gameGrid[2][4].DisplayCellPuissance4() << "  |  " << gameGrid[2][5].DisplayCellPuissance4() << "  |  " << gameGrid[2][6].DisplayCellPuissance4() << "  |  " << endl;

	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;

	cout << "|  " << gameGrid[1][0].DisplayCellPuissance4() << "  |  " << gameGrid[1][1].DisplayCellPuissance4() << "  |  " << gameGrid[1][2].DisplayCellPuissance4() << "  |  " << gameGrid[1][3].DisplayCellPuissance4() << "  |  " << gameGrid[1][4].DisplayCellPuissance4() << "  |  " << gameGrid[1][5].DisplayCellPuissance4() << "  |  " << gameGrid[1][6].DisplayCellPuissance4() << "  |  " << endl;

	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;

	cout << "|  " << gameGrid[0][0].DisplayCellPuissance4() << "  |  " << gameGrid[0][1].DisplayCellPuissance4() << "  |  " << gameGrid[0][2].DisplayCellPuissance4() << "  |  " << gameGrid[0][3].DisplayCellPuissance4() << "  |  " << gameGrid[0][4].DisplayCellPuissance4() << "  |  " << gameGrid[0][5].DisplayCellPuissance4() << "  |  " << gameGrid[0][6].DisplayCellPuissance4() << "  |  " << endl;
	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl << endl;

}