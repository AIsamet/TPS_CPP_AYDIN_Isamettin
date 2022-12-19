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
 * @return  la case si elle est trouv�e
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
 * @return  la case si elle est trouv�e
**/
Cell& Grid::GetCell(const int& line, const int& column) {
	int index = line * GetColumn() + column;
	return gameGrid[index];

}

Cell Grid::GetCell(const int& line, const int& column) const {
	int index = line * GetColumn() + column;
	return gameGrid[index];

}

int Grid::GetCellLineCoordinate(const int& idCell) const {
	int coordinateY = idCell / GetColumn();
	return coordinateY;
}

int Grid::GetCellColumnCoordinate(const int& idCell) const {
	int coordinateX = idCell % GetColumn();
	return coordinateX;
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
	int line = GetCellLineCoordinate(idCell);
	int column = GetCellColumnCoordinate(idCell);
	
	//cout << "line : " << line << " column : " << column << endl;

	//Verifications colonnes
	if (IsPositionInRange(line - 1, column) && !IsCellFree(line - 1, column)) { adjacentCells.push_back(GetCell(line - 1, column)); }
	if (IsPositionInRange(line + 1, column) && !IsCellFree(line + 1, column)) { adjacentCells.push_back(GetCell(line + 1, column)); }
	//Verifications lignes
	if (IsPositionInRange(line, column - 1) && !IsCellFree(line, column - 1)) { adjacentCells.push_back(GetCell(line, column - 1)); }
	if (IsPositionInRange(line, column + 1) && !IsCellFree(line, column + 1)) { adjacentCells.push_back(GetCell(line, column + 1)); }
	//Verfications diagonales top left/bottom right
	if (IsPositionInRange(line + 1, column + 1) && !IsCellFree(line + 1, column + 1)) { adjacentCells.push_back(GetCell(line + 1, column + 1)); }
	if (IsPositionInRange(line - 1, column - 1) && !IsCellFree(line - 1, column - 1)) { adjacentCells.push_back(GetCell(line - 1, column - 1)); }
	//Verfications diagonales top right/bottom left
	if (IsPositionInRange(line + 1, column - 1) && !IsCellFree(line + 1, column - 1)) { adjacentCells.push_back(GetCell(line + 1, column - 1)); }
	if (IsPositionInRange(line - 1, column + 1) && !IsCellFree(line - 1, column + 1)) { adjacentCells.push_back(GetCell(line - 1, column + 1)); }

	return adjacentCells;
}

bool Grid::IsPositionInRange(const int& positionLine, const int& positionColumn) const {
	if (positionLine < 0 || positionLine >= GetColumn() || positionColumn < 0 || positionColumn >= GetLine()) {
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