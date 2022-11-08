#include "Puissance4.h"

Puissance4::Puissance4() {
	InitGrid(4, 7);
	player1 = Player(1, "A");
	player2 = Player(2, "B");
}

Puissance4::Puissance4(string player1Name, string player2Name) {
	InitGrid(4, 7);
	player1 = Player(1, player1Name);
	player2 = Player(2, player2Name);
}

void Puissance4::InitGrid(const int& line, const int& column) {
	gameGrid.resize(line);

	for (int k = 0; k < line; k++) {
		gameGrid[k].resize(column);
	}
	Cell::SetIdStatic(1);
}

void Puissance4::DisplayPlate() const {
	cout << "\033[1;31mJoueur A (X)\033[0m  -  \033[1;32mJoueur B (O)\033[0m" << endl << endl;
	cout << endl;

	cout << "|  " << "1" << "  |  " << "2" << "  |  " << "3" << "  |  " << "4" << "  |  " << "5" << "  |  " << "6" << "  |  " << "7" << "  |  " << endl;


	cout << " _________________________________________" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;
	cout << "|  " << gameGrid[3][0].DisplayCellPuissance4() << "  |  " << gameGrid[3][1].DisplayCellPuissance4() << "  |  " << gameGrid[3][2].DisplayCellPuissance4() << "  |  " << gameGrid[3][3].DisplayCellPuissance4() << "  |  " << gameGrid[3][4].DisplayCellPuissance4() << "  |  " << gameGrid[3][5].DisplayCellPuissance4() << "  |  " << gameGrid[3][6].DisplayCellPuissance4() << "  |  " << endl;

	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;

	cout << "|  " << gameGrid[2][0].DisplayCellPuissance4() << "  |  " << gameGrid[2][1].DisplayCellPuissance4() << "  |  " << gameGrid[2][2].DisplayCellPuissance4() << "  |  " << gameGrid[2][3].DisplayCellPuissance4() << "  |  " << gameGrid[2][4].DisplayCellPuissance4() << "  |  " << gameGrid[2][5].DisplayCellPuissance4() << "  |  " << gameGrid[2][6].DisplayCellPuissance4() << "  |  " << endl;

	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;

	cout << "|  " << gameGrid[1][0].DisplayCellPuissance4() << "  |  " << gameGrid[1][1].DisplayCellPuissance4() << "  |  " << gameGrid[1][2].DisplayCellPuissance4() << "  |  " << gameGrid[1][3].DisplayCellPuissance4() << "  |  " << gameGrid[1][4].DisplayCellPuissance4() << "  |  " << gameGrid[1][5].DisplayCellPuissance4() << "  |  " << gameGrid[1][6].DisplayCellPuissance4() << "  |  " << endl;

	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;

	cout << "|  " << gameGrid[0][0].DisplayCellPuissance4() << "  |  " << gameGrid[0][1].DisplayCellPuissance4() << "  |  " << gameGrid[0][2].DisplayCellPuissance4() << "  |  " << gameGrid[0][3].DisplayCellPuissance4() << "  |  " << gameGrid[0][4].DisplayCellPuissance4() << "  |  " << gameGrid[0][5].DisplayCellPuissance4() << "  |  " << gameGrid[0][6].DisplayCellPuissance4() << "  |  " << endl;
	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl << endl;

}

void Puissance4::InputPlayer(Player player) {

	int input = 0;
	cin >> input;
	
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Veuillez entrer un chiffre valide" << endl;
		cin >> input;
	}

	if (input < 8 && input > 0) {

		for (int ligne = 0; ligne < gameGrid.size(); ligne++) {

			if (gameGrid[ligne][input - 1].GetOwner() == 0) {

				gameGrid[ligne][input - 1].SetOwner(player.GetId());
				break;
			}
			else if (ligne == gameGrid.size() - 1) {
				cout << "La colonne est pleine, veuillez choisir une autre colonne" << endl;
				InputPlayer(player);
			}
		}
	}
	else {
		cout << "Veuillez saisir un chiffre entre 1 et 7" << endl;
		InputPlayer(player);
	}
}

void Puissance4::StartGame() {
	int i = 0;
	Player currentPlayer = player1;
	
	while (!CheckWin(currentPlayer) && !CheckEquality())
	{
		system("cls");
		DisplayPlate();
	
		if (i % 2 == 0) {
			currentPlayer = player1; 
			cout << "Tour \033[1;31mjoueur " << currentPlayer.GetName() << "\033[0m, dans quelle colonne voulez - vous jouer ? " << endl;
		}
		else {
			currentPlayer = player2;
			cout << "Tour \033[1;32mjoueur " << currentPlayer.GetName() << "\033[0m, dans quelle colonne voulez - vous jouer ? " << endl;
		}
		
		InputPlayer(currentPlayer);
		i++;
	}
	
	system("cls");
	DisplayPlate();
	if (CheckWin(currentPlayer)) { cout << "Le joueur " << currentPlayer.GetName() << " a gagne" << endl; }
	else if (CheckEquality()) { cout << "Egalite" << endl; }
}

bool Puissance4::CheckEquality() const {
	int line = 0;
	int column = 0;

	for (line = 0; line < gameGrid.size(); line++)
	{
		for (column = 0; column < gameGrid[0].size(); column++)
		{
			if (gameGrid[line][column].GetOwner() == 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool Puissance4::CheckWin(const Player& player) const {
	if (CheckWinByLine(player) || CheckWinByColumn(player) || CheckWinByDiagonal(player)) {
		return true;
	}
	else {
		return false;
	}
}

bool Puissance4::CheckWinByLine(const Player& player) const {
	int line = 0;
	int column = 0;
	int count = 0;

	for (line = 0; line < gameGrid.size(); line++) {

		for (column = 0; column < gameGrid[0].size(); column++) {

			if (gameGrid[line][column].GetOwner() == player.GetId()) {
				count++;

				if (count == 4) {
					return true;
				}
			}
			else {
				count = 0;
			}
		}
		count = 0;
	}
	return false;
}

bool Puissance4::CheckWinByColumn(const Player& player) const {
	int line = 0;
	int column = 0;
	int count = 0;

	for (column = 0; column < gameGrid[0].size(); column++) {

		for (line = 0; line < gameGrid.size(); line++) {

			if (gameGrid[line][column].GetOwner() == player.GetId()) {
				count++;

				if (count == 4) {
					return true;
				}
			}
			else {
				count = 0;
			}
		}
		count = 0;
	}
	return false;
}

bool Puissance4::CheckWinByDiagonal(const Player& player) const {
	const int gridColumnNumber = gameGrid[0].size() - 1;
	int line = 0;
	int column = 0;
	int totalCount = 0;
	int countDiagonal = 0;

	for (column = 0; column < 4; column++) {

		if (gameGrid[line][column].GetOwner() == player.GetId()) {

			for (countDiagonal = 0; countDiagonal < 4; countDiagonal++) {

				if (gameGrid[line + countDiagonal][column + countDiagonal].GetOwner() == player.GetId()) {
					totalCount++;
				}
				else {
					totalCount = 0;
				}
			}
			if (totalCount == 4) {
				return true;
			}
			else {
				totalCount = 0;
			}

			for (countDiagonal = 0; countDiagonal < 4; countDiagonal++) {

				if (gameGrid[line + countDiagonal][gridColumnNumber - column - countDiagonal].GetOwner() == player.GetId()) {
					totalCount++;
				}
				else {
					totalCount = 0;
				}
			}
			if (totalCount == 4) {
				return true;
			}
			else {
				totalCount = 0;
			}
		}
	}
	return false;
}