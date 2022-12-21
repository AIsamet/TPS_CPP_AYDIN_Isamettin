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
	//on recupere cells ajacents au input et on verifie si ses cells ajacents sont flipables
	vector<Cell> adjacentCells = grid.GetOpponentAdjacentCells(input, player.GetId());

	for (int i = 0; i < adjacentCells.size(); i++) {
		if (IsOthelloCellFlipable(grid, player, input, adjacentCells[i].GetIdCell())) {
			return true;
		}
	}
	return false;
}

bool Checks::IsOthelloCellFlipable(const Grid& grid, const Player& player, const int& input, const int& adjacentCellIdToCheck) {
	//on prends un input et un cell adjacent puis on verifie si le input va donner lieu a un flip du cell adjacent
	vector<Cell> FlipableCells = Checks::GetOthelloFlipableCell(grid, player, input, adjacentCellIdToCheck);
	//on prends le dernier element valide
	if (FlipableCells[FlipableCells.size() - 1].GetOwner() == player.GetId()) {
		return true;
	}
	return false;
}

vector<Cell> Checks::GetCellsToFlipOthello(const Grid& grid, const Player& player, const int& input) {
	vector<Cell> adjacentCells = grid.GetOpponentAdjacentCells(input-1, player.GetId());
	
	vector<Cell> CellsToFlip = GetOthelloFlipableCell(grid, player, input-1, adjacentCells[0].GetIdCell()-1);
	for (int i = 0; i < CellsToFlip.size(); i++) {
		cout << "adj : " << adjacentCells[0].GetIdCell();
		cout << "flip : " << CellsToFlip[i].GetIdCell()+1 << endl;
	}
	return CellsToFlip;
}

//from input to adjacent cell
vector<Cell> Checks::GetOthelloFlipableCell(const Grid& grid, const Player& player, const int& input, const int& adjacentCellIdToCheck){
	//on recupere les cells flipables
	vector<Cell> FlipableCells;
	int lineAjacentCellIdToCheck = grid.GetCellLineCoordinate(adjacentCellIdToCheck);
	int columnAjacentCellIdToCheck = grid.GetCellColumnCoordinate(adjacentCellIdToCheck);
	int positions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1},   // 3 positions above
							{0, -1 },		   {0, 1 },   // 2 positions on same row
							{1, -1,}, {1, 0 }, {1, 1 } }; // 3 positions below
	int direction = grid.GetAdjacentCellPosition(input, adjacentCellIdToCheck);
	int current_line = lineAjacentCellIdToCheck;
	int current_column = columnAjacentCellIdToCheck;

	while (grid.IsPositionInRange(current_line + positions[direction][0], current_column + positions[direction][1])) {

		current_line += positions[direction][0];
		current_column += positions[direction][1];
		int currentOwner = grid.GetCellOwner(current_line, current_column);
		FlipableCells.push_back(grid.GetCell(current_line, current_column));
		if (currentOwner == player.GetId() || currentOwner == 0) {
			break;
		}
	}

	return FlipableCells;
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
