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

int Grid::GetCellOwner(const int& idCell) {
	return gameGrid[idCell].GetOwner();
}

int Grid::GetCellOwner(const int& idCell) const {
	return GetCell(idCell).GetOwner();
}

int Grid::GetCellOwner(const int& line, const int& column) {
	return GetCell(line, column).GetOwner();
}

int Grid::GetCellOwner(const int& line, const int& column) const {
	return GetCell(line, column).GetOwner();
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