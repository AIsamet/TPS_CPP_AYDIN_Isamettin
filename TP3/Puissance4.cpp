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

//génére une grille de jeu
void Puissance4::InitGrid(const int& line, const int& column) {
	gameGrid.resize(line);

	for (int k = 0; k < line; k++) {
		gameGrid[k].resize(column);
	}
	Cell::SetIdStatic(1);
}

//affiche la grille de jeu
void Puissance4::DisplayPlate() const {
	system("cls");

	cout << "\033[1;31mJoueur " << player1.GetName() << "\033[0m  -  \033[1;32mJoueur " << player2.GetName() << "\033[0m" << endl << endl;
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

//demande une entrée au joueur
void Puissance4::InputPlayer(Player player) {

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

	else {
		for (int ligne = 0; ligne < gameGrid.size(); ligne++) {

			if (gameGrid[ligne][BotRandomInputGenerator()].GetOwner() == 0) {

				gameGrid[ligne][BotRandomInputGenerator()].SetOwner(player.GetId());
				break;
			}
		}
	}
}

//genere une case vide a jouer aléatoirement par le bot
int Puissance4::BotRandomInputGenerator() {
	srand(time(NULL));
	int randomPlay;

	while (true) {
		
		randomPlay = rand() % 7;
		for (int ligne = 0; ligne < gameGrid.size(); ligne++) {

			if (gameGrid[ligne][randomPlay].GetOwner() == 0) {
				return randomPlay;
			}
		}
	}
}

//fonction qui demande au joueur le type de jeu a lancer
void Puissance4::AskGameType() {

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
void Puissance4::AskPlayersName() {
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
Player Puissance4::PlayGame() {
	int i = 0;
	Player currentPlayer = player1;

	while (!CheckWin(currentPlayer) && !CheckEquality())
	{
		DisplayPlate();

		if (i % 2 == 0) {
			currentPlayer = player1;
			cout << "Tour \033[1;31mjoueur " << currentPlayer.GetName() << "\033[0m, dans quelle colonne voulez - vous jouer ? " << endl;
		}

		else {
			currentPlayer = player2;

			if (currentPlayer.GetIsBot() == 0) {
				cout << "Tour \033[1;32mjoueur " << currentPlayer.GetName() << "\033[0m, dans quelle colonne voulez - vous jouer ? " << endl;
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
void Puissance4::StartGame() {
	
	AskGameType(); //demande le type de jeu
	AskPlayersName();
	Player winner = PlayGame(); //fait jouer les joueurs jusqu'a avoir un gagnant ou égalité
	
	DisplayPlate();
	if (CheckWin(winner)) { cout << "Le joueur " << winner.GetName() << " a gagne" << endl; }
	else if (CheckEquality()) { cout << "Egalite" << endl; }
}

//verifie le cas d'une égalité
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

//verifie s'il y a un gagnant
bool Puissance4::CheckWin(const Player& player) const {
	if (CheckWinByLine(player) || CheckWinByColumn(player) || CheckWinByDiagonal(player)) {
		return true;
	}
	else {
		return false;
	}
}

//verifie s'il y a un gagnant par ligne
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

//verifie s'il y a un gagnant par colonne
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

//verifie s'il y a un gagnant par diagonal
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