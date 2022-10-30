#include "Morpion.h"

Morpion::Morpion() {
}

Morpion::Morpion(int i, int j) {
	InitGrid(i, j);
	this->player1 = Player(1, "A");
	this->player2 = Player(2, "B");
}

Player Morpion::GetPlayer() {
	return player1;
}

void Morpion::InitGame() {
	int i = 0;
	Player currentPlayer = player1;
	while (CheckWin(currentPlayer) == 0 && CheckEquality() == 0)
	{
		system("cls");
		DisplayPlate();
		if (i % 2 == 0) { currentPlayer = player1; }
		else { currentPlayer = player2; }
		
		cout << "Tour joueur " << currentPlayer.GetName() << ", dans quelle case voulez - vous jouer ? " << endl;
		InputPlayer(currentPlayer);
		i++;
	}

	system("cls");
	DisplayPlate();
	if (CheckWin(currentPlayer) == 1) { cout << "Le joueur " << currentPlayer.GetName() << " a gagne" << endl; }
	else if (CheckEquality() == 1) { cout << "Egalite" << endl; }
}

void Morpion::InitGrid(int i, int j) {
	gameGrid.resize(i);

	for (int k = 0; k < i; k++) {
		gameGrid[k].resize(j);
	}

}

bool Morpion::CheckEquality() {
	int line = 0;
	int column = 0;

	for (line = 0; line < 3; line++)
	{
		for (column = 0; column < 3; column++)
		{
			if (gameGrid[line][column].GetOwner() == 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool Morpion::CheckWin(Player player) {
	if (CheckWinByLine(player) == 1 || CheckWinByColumn(player) == 1 || CheckWinByDiagonal(player) == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool Morpion::CheckWinByLine(Player player) {
	int line = 0;
	int column = 0;
	int count = 0;

	for (line = 0; line < 3; line++) {

		for (column = 0; column < 3; column++) {

			if (gameGrid[line][column].GetOwner() == player.GetId()) {
				count++;
			}
		}
		if (count == 3) {
			return true;
		}
		count = 0;
	}
}

bool Morpion::CheckWinByColumn(Player player) {
	int line = 0;
	int column = 0;
	int count = 0;

	for (column = 0; column < 3; column++) {

		for (line = 0; line < 3; line++) {

			if (gameGrid[line][column].GetOwner() == player.GetId()) {
				count++;
			}
		}
		if (count == 3) {
			return true;
		}
		count = 0;
	}
}

bool Morpion::CheckWinByDiagonal(Player player) {
	int line = 0;
	int column = 0;
	int count = 0;

	for (line = 0; line < 3; line++) {

		if (gameGrid[line][line].GetOwner() == player.GetId()) {
			count++;
		}
	}
	if (count == 3) {
		return true;
	}
	count = 0;

	for (line = 0; line < 3; line++) {

		if (gameGrid[line][2 - line].GetOwner() == player.GetId()) {
			count++;
		}
	}
	if (count == 3) {
		return true;
	}
	count = 0;
}

Cell& Morpion::GetCell(int idCell) {
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



void Morpion::InputPlayer(Player player) {

	int input = 0;
	cin >> input;
	if (input < 10 && input > 0) {
		if (GetCell(input - 1).GetOwner() == 0) {
			GetCell(input - 1).SetOwner(player.GetId());
		}
		else {
			cout << "Case deja prise" << endl; InputPlayer(player);
		}
	}
	else {
		cout << "Veuillez saisir un chiffre entre 1 et 9" << endl;
		InputPlayer(player);
	}
}


void Morpion::DisplayPlate() {
	cout << "Player A (X)  -  Player B (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << gameGrid[0][0].DisplayCell() << "  |  " << gameGrid[0][1].DisplayCell() << "  |  " << gameGrid[0][2].DisplayCell() << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << gameGrid[1][0].DisplayCell() << "  |  " << gameGrid[1][1].DisplayCell() << "  |  " << gameGrid[1][2].DisplayCell() << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << gameGrid[2][0].DisplayCell() << "  |  " << gameGrid[2][1].DisplayCell() << "  |  " << gameGrid[2][2].DisplayCell() << endl;

	cout << "     |     |     " << endl << endl;
}



