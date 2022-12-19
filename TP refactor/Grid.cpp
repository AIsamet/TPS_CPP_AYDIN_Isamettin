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

int Grid::GetCellXCoordinate(const int& idCell) const {
	int coordinateX = idCell % GetColumn();
	return coordinateX;
}

int Grid::GetCellYCoordinate(const int& idCell) const {
	int coordinateY = idCell / GetColumn();
	return coordinateY;
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

bool Grid::IsCellFree(const int& idCell) const {
	if (GetCellOwner(idCell) == 0) {
		return true;
	}
	else
		return false;
}

bool Grid::IsCellFree(const int& line, const int& column) const {
	if (GetCellOwner(line, column) == 0) {
		return true;
	}
	else
		return false;
}

vector<Cell> Grid::GetAdjacentCell(const int& idCell) const {
	vector<Cell> adjacentCells;
	int x = GetCellXCoordinate(idCell);
	int y = GetCellYCoordinate(idCell);

	//Verifications colonnes
	if (!IsCellFree(x - 1, y) && IsPositionInRange(x - 1, y)) { adjacentCells.push_back(GetCell(x - 1, y)); }
	if (!IsCellFree(x + 1, y) && IsPositionInRange(x + 1, y)) { adjacentCells.push_back(GetCell(x + 1, y)); }
	//Verifications lignes
	if (!IsCellFree(x, y - 1) && IsPositionInRange(x, y - 1)) { adjacentCells.push_back(GetCell(x, y - 1)); }
	if (!IsCellFree(x, y + 1) && IsPositionInRange(x, y + 1)) { adjacentCells.push_back(GetCell(x, y + 1)); }
	//Verfications diagonales top left/bottom right
	if (!IsCellFree(x + 1, y + 1) && IsPositionInRange(x + 1, y + 1)) { adjacentCells.push_back(GetCell(x + 1, y + 1)); }
	if (!IsCellFree(x - 1, y - 1) && IsPositionInRange(x - 1, y - 1)) { adjacentCells.push_back(GetCell(x - 1, y - 1)); }
	//Verfications diagonales top right/bottom left
	if (!IsCellFree(x + 1, y - 1) && IsPositionInRange(x + 1, y - 1)) { adjacentCells.push_back(GetCell(x + 1, y - 1)); }
	if (!IsCellFree(x - 1, y + 1) && IsPositionInRange(x - 1, y + 1)) { adjacentCells.push_back(GetCell(x - 1, y + 1)); }

	return adjacentCells;
}

bool Grid::IsPositionInRange(const int& positionX, const int& positionY) const {
	if (positionX < 0 || positionX > GetLine() || positionY < 0 || positionY > GetColumn()) {
		return false;
	} return true;
}

bool Grid::SetCellOwnerIfEmpty(const int& idCelll, const int& value) {
	if (IsCellFree(idCelll)) {
		GetCell(idCelll).SetOwner(value);
		return true;
	}
	return false;
}

bool Grid::SetCellOwnerIfEmpty(const int& line, const int& column, const int& value) {
	if (IsCellFree(line, column)) {
		GetCell(line, column).SetOwner(value);
		return true;
	}
	return false;
}