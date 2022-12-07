#include "Puissance4.h"

/**
 * @brief   Construit un nouveau jeu de puissance 4
 * @params  player1Name : nom du joueur 1, player2Name : nom du joueur 2 ou IA
**/
Puissance4::Puissance4() {
	grid = Grid(4, 7);
	player1 = Player(1, "A");
	player2 = Player(2, "B");
}
Puissance4::Puissance4(string player1Name, string player2Name) {
	grid = Grid(4, 7);
	player1 = Player(1, player1Name);
	player2 = Player(2, player2Name);
}

/**
 * @brief   Lance un tour jusqu'a ce qu'il y ait victoire ou egalite
 * @return  joueur actuel
**/
Player Puissance4::PlayRound() {
	int i = 0;
	Player currentPlayer = player1;

	while (!CheckWin(currentPlayer) && !CheckEquality())
	{
		system("cls");
		Player::DisplayPlayersPuissance4(GetPlayer1(), GetPlayer2());
		grid.DisplayGridPuissance4();

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

		Inputs::InputPuissance4(grid,currentPlayer);
		i++;
	}
	return currentPlayer;
}

/**
 * @brief   Lance une partie
 * @return  void
**/
void Puissance4::StartGame() {
	AskGameMode(); // demande le type de jeu
	AskPlayersNames();
	Player winner = PlayRound(); // fait jouer les joueurs jusqu'a avoir un gagnant ou égalité

	system("cls");
	Player::DisplayPlayersPuissance4(GetPlayer1(), GetPlayer2());
	grid.DisplayGridPuissance4();
	if (CheckWin(winner)) { cout << "Le joueur " << winner.GetName() << " a gagne" << endl; }
	else if (CheckEquality()) { cout << "Egalite" << endl; }
}

/**
 * @brief   Verifie s'il y a egalite
 * @return  true s'il y a egalite, false sinon
**/
bool Puissance4::CheckEquality() const {
	int line = 0;
	int column = 0;

	for (line = 0; line < grid.GetGameGrid().size(); line++)
	{
		for (column = 0; column < grid.GetGameGrid()[0].size(); column++)
		{
			if (grid.GetGameGrid()[line][column].GetOwner() == 0)
			{
				return false;
			}
		}
	}
	return true;
}

/**
 * @brief   Verifie si un joueur a gagne
 * @param   player : joueur
 * @return  true si le joueur a gagne, false sinon
**/
bool Puissance4::CheckWin(const Player& player) const {
	return CheckWinByLine(player) || CheckWinByColumn(player) || CheckWinByDiagonal(player);
}

/**
 * @brief   Verifie si un joueur a gagne en ligne
 * @param   player : joueur
 * @return  true si le joueur a gagne en ligne, false sinon
**/
bool Puissance4::CheckWinByLine(const Player& player) const {
	int line = 0;
	int column = 0;
	int count = 0;

	for (line = 0; line < grid.GetGameGrid().size(); line++) {

		for (column = 0; column < grid.GetGameGrid()[0].size(); column++) {

			if (grid.GetGameGrid()[line][column].GetOwner() == player.GetId()) {
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

/**
 * @brief   Verifie si un joueur a gagne en colonne
 * @param   player : joueur
 * @return  true si le joueur a gagne en colonne, false sinon
**/
bool Puissance4::CheckWinByColumn(const Player& player) const {
	int line = 0;
	int column = 0;
	int count = 0;

	for (column = 0; column < grid.GetGameGrid()[0].size(); column++) {

		for (line = 0; line < grid.GetGameGrid().size(); line++) {

			if (grid.GetGameGrid()[line][column].GetOwner() == player.GetId()) {
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

/**
 * @brief   Verifie si un joueur a gagne en diagonale
 * @param   player : joueur
 * @return  true si le joueur a gagne en diagonale, false sinon
**/
bool Puissance4::CheckWinByDiagonal(const Player& player) const {
	const int gridColumnNumber = grid.GetGameGrid()[0].size() - 1;
	int line = 0;
	int column = 0;
	int totalCount = 0;
	int countDiagonal = 0;

	for (column = 0; column < 4; column++) {

		if (grid.GetGameGrid()[line][column].GetOwner() == player.GetId()) {

			for (countDiagonal = 0; countDiagonal < 4; countDiagonal++) {

				if (grid.GetGameGrid()[line + countDiagonal][column + countDiagonal].GetOwner() == player.GetId()) {
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

				if (grid.GetGameGrid()[line + countDiagonal][gridColumnNumber - column - countDiagonal].GetOwner() == player.GetId()) {
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