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
	vector<Cell> adjacentCells = grid.GetAdjacentCells(input - 1);

	//cout << adjacentCells.size() << " adj cells : " << endl;
	//for (int i = 0; i < adjacentCells.size(); i++) {
	//	cout << adjacentCells[i].GetIdCell() << endl;
	//}

	for (int i = 0; i < adjacentCells.size(); i++) {
		if (adjacentCells[i].GetOwner() != player.GetId()/* && IsOthelloCellFlipable(grid, player, input, adjacentCells[i].GetIdCell())*/) {
			return true;
		}
	}
	return false;
}

bool Checks::IsOthelloCellFlipable(const Grid& grid, const Player& player, const int& input, const int& cellIdToCheck){
	int lineInput = grid.GetCellLineCoordinate(input);
	int columnInput = grid.GetCellColumnCoordinate(input);

	int lineCellIdToCheck = grid.GetCellLineCoordinate(cellIdToCheck);
	int columnCellIdToCheck = grid.GetCellColumnCoordinate(cellIdToCheck);

	int positions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1},  // 3 positions above
							{0, -1 },		   {0, 1 },   // 2 positions on same row
							{1, -1,}, {1, 0 }, {1, 1 } }; // 3 positions below

	int direction = grid.GetAdjacentCellPosition(input, cellIdToCheck);
	int current_line = lineCellIdToCheck;
	int current_column = columnCellIdToCheck;

	while (grid.GetCellOwner(current_line, current_column) != grid.GetCellOwner(lineInput, columnInput)) {
		current_line = positions[direction][0];
		current_column = positions[direction][1];
	}
	return false;
}

	bool Checks::IsInputValidGameModes(const int& input) {
		if (input < 3 && input > 0) {
			return true;
		}
		return false;
	}

	bool Checks::IsPlayerBot(const Player & player) {
		if (player.GetIsBot() == 1) { return true; }
		else if (player.GetIsBot() == 0) { return false; }
	}
