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

vector<Cell> Grid::GetAdjacentCells(const int& idCell) const {
	vector<Cell> adjacentCells;
	int line = GetCellLineCoordinate(idCell);
	int column = GetCellColumnCoordinate(idCell);

	for (int i : {-1, 0, 1}) {
		for (int j : {-1, 0, 1}) {
			if (IsPositionInRange(line + i, column + j) && !IsCellFree(line + i, column + j)) {
				adjacentCells.push_back(GetCell(line + i, column + j));
			}
		}
	}

	return adjacentCells;
}


int Grid::GetAdjacentCellPosition(const int& idCell, const int& cellIdToCheck) const {
	int line = GetCellLineCoordinate(idCell);
	int column = GetCellColumnCoordinate(idCell);
	int lineCellIdToCheck = GetCellLineCoordinate(cellIdToCheck);
	int columnCellIdToCheck = GetCellColumnCoordinate(cellIdToCheck);

	int positions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, // 3 positions above
						    {0, -1},		   {0, 1}, // 2 positions on same row
							{1, -1}, {1, 0}, {1, 1} }; // 3 positions below

	for (int i = 0; i < sizeof(positions); i++) {
		if (line + positions[i][0] == lineCellIdToCheck && column + positions[i][1] == columnCellIdToCheck) {
			return i;
		}
	}

	//1 = diagonal top left
	//2 = haut
	//3 = diagonal top right
	//4 = left
	//5 = right
	//6 = diagonal bottom left
	//7 = bottom
	//8 = diagonal bottom right
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
