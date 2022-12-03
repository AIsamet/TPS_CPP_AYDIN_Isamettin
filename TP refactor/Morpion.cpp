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

	cout << "\033[1;31mJoueur " << player1.GetName() << " (X)\033[0m  -  \033[1;32mJoueur " << player2.GetName() << " (O)\033[0m" << endl << endl;
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

	if (player.GetIsBot() == 0) {
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

	else {
		GetCellPositionFromId(BotRandomInputGenerator()).SetOwner(player.GetId());
	}
}

//genere une case vide a jouer aléatoirement par le bot
int Morpion::BotRandomInputGenerator() {
	srand(time(NULL));
	int randomPlay = rand() % 10;

	while (GetCellPositionFromId(randomPlay).GetOwner() != 0) {
		randomPlay = rand() % 10;
	}
	
	return randomPlay;
}

//fonction qui demande au joueur le type de jeu a lancer
void Morpion::AskGameType() {
	
	system("cls");
	int input = 0;

	cout << "A quelle mode de jeu voulez vous jouer ? " << endl;
	cout << "1 - Joueur contre Joueur" << endl;
	cout << "2 - Joueur contre IA" << endl;
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
	if (input < 3 && input > 0) {
		if (input == 1) { SetGameMode(0); }
		else if (input == 2) { SetGameMode(1); player2.SetName("IA"); player2.SetIsBot(1); }
	}
	else {
		cout << "Veuillez saisir un choix valide" << endl;
		AskGameType();
	}
}

//fonction qui demande aux joueurs leur pseudonyme
void Morpion::AskPlayersName() {
	system("cls");
	string namePlayer;

	cout << "Entrez le nom du joueur 1" << endl;
	cin >> namePlayer;
	player1.SetName(namePlayer);

	if (!player2.GetIsBot()) {
		cout << "\nEntrez le nom du joueur 2" << endl;
		cin >> namePlayer;
		player2.SetName(namePlayer);
	}
}

//fait jouer les tours des joueurs jusqu'a ce qu'il y ait un gagnant ou égalité
Player Morpion::PlayGame() {
	int i = 0;
	Player currentPlayer = player1;

	while (!CheckWin(currentPlayer) && !CheckEquality())
	{
		system("cls");
		DisplayPlate();

		if (i % 2 == 0) {
			currentPlayer = player1;
			cout << "Tour \033[1;31mjoueur " << currentPlayer.GetName() << "\033[0m, dans quelle case voulez - vous jouer ? " << endl;
		}

		else {
			currentPlayer = player2;

			if (currentPlayer.GetIsBot() == 0) {
				cout << "Tour \033[1;32mjoueur " << currentPlayer.GetName() << "\033[0m, dans quelle case voulez - vous jouer ? " << endl;
			}
			else {
				cout << "Le \033[1;32mjoueur " << currentPlayer.GetName() << "\033[0m joue son tour" << endl;
				this_thread::sleep_for(chrono::milliseconds(500));
			}
		}

		InputPlayer(currentPlayer);
		i++;
	}
	return currentPlayer;
}

//lance la partie
void Morpion::StartGame() {

	AskGameType(); //demande le type de jeu
	AskPlayersName();
	Player winner = PlayGame(); //fait jouer les joueurs jusqu'a avoir un gagnant ou égalité
	
	system("cls");
	DisplayPlate();
	if (CheckWin(winner)) { cout << "Le joueur " << winner.GetName() << " a gagne" << endl; }
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