#include "Checks.h"

/**
 * @brief   Verifie si une entrée est un nombre
 * @params  input : l'entrée a vérifier
 * @return  bool
**/
bool Checks::IsNumericInput(const int& input) {
	if (!std::cin.good()) {
		return false;
	}
	return true;
}

/**
 * @brief   Verifie si l'entrée est valide pour un jeu de morpion
 * @params  input : l'entrée a vérifier
 * @return  bool
**/
bool Checks::IsInputByCellValid(const int& input, const int& maxInput) {
	if (input <= maxInput && input > 0) {
		return true;
	}
	return false;
}

/**
 * @brief   Verifie si l'entrée est valide pour un jeu de puissance 4
 * @params  input : l'entrée a vérifier
 * @return  bool
**/
bool Checks::IsInputByColumnValid(const int& input, const int& maxInput) {
	if (input <= maxInput && input > 0) {
		return true;
	}
	return false;
}

bool Checks::IsOthelloCellPlayable(const Grid& grid, const Player& player, const int& input) {
	//adjacent cell is the owned cell we want to compare with adjacent playables
	vector<Cell> adjacentCells = grid.GetNotFreeAdjacentCells(input);

	for (int i = 0; i < adjacentCells.size(); i++) {
		if (adjacentCells[i].GetOwner() != player.GetId() && IsOthelloCellValid(grid, player, input, adjacentCells[i].GetIdCell())) {
			return true;
		}
	}
	return false;
}

//from input to adjacent cell
bool Checks::IsOthelloCellValid(const Grid& grid, const Player& player, const int& input, const int& adjacentCellIdToCheck) {

	int lineAjacentCellIdToCheck = grid.GetCellLineCoordinate(adjacentCellIdToCheck);
	int columnAjacentCellIdToCheck = grid.GetCellColumnCoordinate(adjacentCellIdToCheck);
	int positions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1},  // 3 positions above
							{0, -1 },		   {0, 1 },   // 2 positions on same row
							{1, -1,}, {1, 0 }, {1, 1 } }; // 3 positions below
	int direction = grid.GetAdjacentCellPosition(input, adjacentCellIdToCheck);
	int current_line = lineAjacentCellIdToCheck;
	int current_column = columnAjacentCellIdToCheck;

	while (grid.IsPositionInRange(current_line + positions[direction][0], current_column + positions[direction][1])) {

		current_line += positions[direction][0];
		current_column += positions[direction][1];
		int currentOwner = grid.GetCellOwner(current_line, current_column);

		if (currentOwner == player.GetId()) {
			return true;
		}
	}
	return false;
}

bool Checks::IsInputValidGameModes(const int& input) {
	if (input < 3 && input > 0) {
		return true;
	}
	return false;
}

bool Checks::IsPlayerBot(const Player& player) {
	if (player.GetIsBot() == 1) { return true; }
	else if (player.GetIsBot() == 0) { return false; }
}
