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



bool Checks::IsOthelloCellPlayable(const Grid& grid, const Player& player, const int& baseCell) {
	//adjacent cell is the owned cell we want to compare with adjacent playables ()
	vector<Cell> adjacentCells = grid.GetAdjacentCells(baseCell);

	for (int i = 0; i < adjacentCells.size(); i++) {
		if (adjacentCells[i].GetOwner() != player.GetId() && IsOthelloCellFlipable(grid, player, baseCell, adjacentCells[i].GetIdCell())) {
			cout << "adj : " << adjacentCells[i].GetIdCell() << endl;
			cout << "base cell : " << baseCell << endl;
			return true;
		}
	}
	return false;
}

bool Checks::IsOthelloCellFlipable(const Grid& grid, const Player& player, const int& baseCell, const int& adjacentCellIdToCheck){
	int lineInput = grid.GetCellLineCoordinate(baseCell);
	int columnInput = grid.GetCellColumnCoordinate(baseCell);

	int lineCellIdToCheck = grid.GetCellLineCoordinate(adjacentCellIdToCheck);
	int columnCellIdToCheck = grid.GetCellColumnCoordinate(adjacentCellIdToCheck);

	int positions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1},  // 3 positions above
							{0, -1 },		   {0, 1 },   // 2 positions on same row
							{1, -1,}, {1, 0 }, {1, 1 } }; // 3 positions below

	int direction = grid.GetAdjacentCellPosition(baseCell, adjacentCellIdToCheck);
	int current_line = lineCellIdToCheck;
	int current_column = columnCellIdToCheck;
	//cout << "base line : " << current_line << endl;
	//cout << "base column : " << current_column << endl;
	//cout << "to line : " << current_line << endl;
	//cout << "to column : " << current_column << endl;
	//cout << "current direction : " << direction << endl;

	while (grid.IsPositionInRange(current_line, current_column) && 
		  (grid.GetCellOwner(current_line, current_column) != grid.GetCellOwner(lineInput, columnInput))) {
		current_line += positions[direction][0];
		current_column += positions[direction][1];
		//cout << "current line : " << current_line << endl;
		//cout << "current column : " << current_column << endl;
	}
	

	return true;
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
