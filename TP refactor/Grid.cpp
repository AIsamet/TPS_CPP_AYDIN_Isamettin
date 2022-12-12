#include "Grid.h"

/**
 * @brief   Construit une nouvelle grille
 * @params  line : nombre de lignes, column : nombre de colonnes
**/
Grid::Grid()
{
}

Grid::Grid(const int& line, const int& column) {
	InitializeSizeGrid(line, column);
	InitializeGameGrid(line, column);
}

/**
 * @brief   Retourne une case a partir de son id
 * @params  idCell : id de la case
 * @return  la case si elle est trouvée
**/
Cell& Grid::GetCell(const int& idCell) {
	return gameGrid[idCell];
}

Cell Grid::GetCell(const int& idCell) const {
	return gameGrid[idCell];
}

/**
 * @brief   Retourne une case a partir d'une ligne et une colonne
 * @params  line : ligne de la case, column : colonne de la case
 * @return  la case si elle est trouvée
**/
Cell& Grid::GetCell(const int& line, const int& column) {
	int index = line * GetColumn() + column;
	return gameGrid[index];

}

Cell Grid::GetCell(const int& line, const int& column) const {
	int index = line * GetColumn() + column;
	return gameGrid[index];

}

/**
 * @brief   Initialise la grille de jeu
 * @params  line : nombre de lignes, column : nombre de colonnes
**/
void Grid::InitializeGameGrid(const int& line, const int& column) {
	for (int i = 1; i <= line * column; i++) {
		gameGrid.push_back(Cell(i));
	}
}

/**
 * @brief   Initialise le pair qui contient la taille de la grille
 * @params  line : nombre de lignes, column : nombre de colonnes
**/
void Grid::InitializeSizeGrid(const int& line, const int& column) {
	sizeGrid.first = line;
	sizeGrid.second = column;
}

/**
 * @brief   Affiche la grille de jeu (morpion)
 * @return  void
**/
void Grid::DisplayGridMorpion() const {
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << gameGrid[0].DisplayCellMorpion() << "  |  " << gameGrid[1].DisplayCellMorpion() << "  |  " << gameGrid[2].DisplayCellMorpion() << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << gameGrid[3].DisplayCellMorpion() << "  |  " << gameGrid[4].DisplayCellMorpion() << "  |  " << gameGrid[5].DisplayCellMorpion() << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << gameGrid[6].DisplayCellMorpion() << "  |  " << gameGrid[7].DisplayCellMorpion() << "  |  " << gameGrid[8].DisplayCellMorpion() << endl;

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
	cout << "|  " << gameGrid[21].DisplayCellPuissance4() << "  |  " << gameGrid[22].DisplayCellPuissance4() << "  |  " << gameGrid[23].DisplayCellPuissance4() << "  |  " << gameGrid[24].DisplayCellPuissance4() << "  |  " << gameGrid[25].DisplayCellPuissance4() << "  |  " << gameGrid[26].DisplayCellPuissance4() << "  |  " << gameGrid[27].DisplayCellPuissance4() << "  |  " << endl;

	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;

	cout << "|  " << gameGrid[14].DisplayCellPuissance4() << "  |  " << gameGrid[15].DisplayCellPuissance4() << "  |  " << gameGrid[16].DisplayCellPuissance4() << "  |  " << gameGrid[17].DisplayCellPuissance4() << "  |  " << gameGrid[18].DisplayCellPuissance4() << "  |  " << gameGrid[19].DisplayCellPuissance4() << "  |  " << gameGrid[20].DisplayCellPuissance4() << "  |  " << endl;

	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;

	cout << "|  " << gameGrid[7].DisplayCellPuissance4() << "  |  " << gameGrid[8].DisplayCellPuissance4() << "  |  " << gameGrid[9].DisplayCellPuissance4() << "  |  " << gameGrid[10].DisplayCellPuissance4() << "  |  " << gameGrid[11].DisplayCellPuissance4() << "  |  " << gameGrid[12].DisplayCellPuissance4() << "  |  " << gameGrid[13].DisplayCellPuissance4() << "  |  " << endl;

	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;

	cout << "|  " << gameGrid[0].DisplayCellPuissance4() << "  |  " << gameGrid[1].DisplayCellPuissance4() << "  |  " << gameGrid[2].DisplayCellPuissance4() << "  |  " << gameGrid[3].DisplayCellPuissance4() << "  |  " << gameGrid[4].DisplayCellPuissance4() << "  |  " << gameGrid[5].DisplayCellPuissance4() << "  |  " << gameGrid[6].DisplayCellPuissance4() << "  |  " << endl;
	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl << endl;

}