#include "Morpion.h"

Morpion::Morpion() {
	InitGrid(3, 3);
	player1 = Player(1, "A");
	player2 = Player(2, "B");
}

Morpion::Morpion(string player1Name, string player2Name) {
	InitGrid(3, 3);
	player1 = Player(1, player1Name);
	player2 = Player(2, player2Name);
}

//génére une grille de jeu
void Morpion::InitGrid(const int& line, const int& column) {
	gameGrid.resize(line);

	for (int k = 0; k < line; k++) {
		gameGrid[k].resize(column);
	}
	Cell::SetIdStatic(1);
}

//permet de retourner un Cell a partir de son id
Cell& Morpion::GetCellPositionFromId(const int& idCell) {
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

//affiche la grille de jeu
void Morpion::DisplayPlate() const {
	cout << "\033[1;31mJoueur A (X)\033[0m  -  \033[1;32mJoueur B (O)\033[0m" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << gameGrid[0][0].DisplayCellMorpion() << "  |  " << gameGrid[0][1].DisplayCellMorpion() << "  |  " << gameGrid[0][2].DisplayCellMorpion() << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << gameGrid[1][0].DisplayCellMorpion() << "  |  " << gameGrid[1][1].DisplayCellMorpion() << "  |  " << gameGrid[1][2].DisplayCellMorpion() << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << gameGrid[2][0].DisplayCellMorpion() << "  |  " << gameGrid[2][1].DisplayCellMorpion() << "  |  " << gameGrid[2][2].DisplayCellMorpion() << endl;

	cout << "     |     |     " << endl << endl;
}

//demande une entrée au joueur
void Morpion::InputPlayer(Player player) {

	int input = 0;
	cin >> input;

	//verifie si l'entrée est un int
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Veuillez entrer un chiffre valide" << endl;
		cin >> input;
	}

	//verifie si l'entrée est valide
	if (input < 10 && input > 0) {
		
		if (GetCellPositionFromId(input - 1).GetOwner() == 0) {
			
			GetCellPositionFromId(input - 1).SetOwner(player.GetId());
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

//lance la partie
void Morpion::StartGame() {
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

//verifie le cas d'une égalité
bool Morpion::CheckEquality() const {
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

//verifie s'il y a un gagnant
bool Morpion::CheckWin(const Player& player) const {
	if (CheckWinByLine(player) || CheckWinByColumn(player) || CheckWinByDiagonal(player)) {
		return true;
	}
	else {
		return false;
	}
}

//verifie s'il y a un gagnant par ligne
bool Morpion::CheckWinByLine(const Player& player) const {
	int line = 0;
	int column = 0;
	int count = 0;

	for (line = 0; line < gameGrid.size(); line++) {

		for (column = 0; column < gameGrid[0].size(); column++) {

			if (gameGrid[line][column].GetOwner() == player.GetId()) {
				count++;
			}
		}
		if (count == 3) {
			return true;
		}
		count = 0;
	}
	return false;
}

//verifie s'il y a un gagnant par colonne
bool Morpion::CheckWinByColumn(const Player& player) const {
	int line = 0;
	int column = 0;
	int count = 0;

	for (column = 0; column < gameGrid[0].size(); column++) {

		for (line = 0; line < gameGrid.size(); line++) {

			if (gameGrid[line][column].GetOwner() == player.GetId()) {
				count++;
			}
		}
		if (count == 3) {
			return true;
		}
		count = 0;
	}
	return false;
}

//verifie s'il y a un gagnant par diagonal
bool Morpion::CheckWinByDiagonal(const Player& player) const {
	int line = 0;
	int column = 0;
	int count = 0;
	int countBis = 0;

	for (line = 0; line < 3; line++) {

		if (gameGrid[line][line].GetOwner() == player.GetId()) {
			count++;
		}
		if (gameGrid[line][2 - line].GetOwner() == player.GetId()) {
			countBis++;
		}
	}
	if (count == 3 || countBis == 3) {
		return true;
	}
	return false;
}