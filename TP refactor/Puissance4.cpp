#include "Puissance4.h"

Puissance4::Puissance4() {
	gameGrid = Grid(4, 7);
	player1 = Player(1, "A");
	player2 = Player(2, "B");
}

Puissance4::Puissance4(string player1Name, string player2Name) {
	gameGrid = Grid(4, 7);
	player1 = Player(1, player1Name);
	player2 = Player(2, player2Name);
}

//fait jouer les tours des joueurs jusqu'a ce qu'il y ait un gagnant ou égalité
Player Puissance4::PlayRound() {
	int i = 0;
	Player currentPlayer = player1;

	while (!CheckWin(currentPlayer) && !CheckEquality())
	{
		system("cls");
		Player::DisplayPlayersPuissance4(GetPlayer1(), GetPlayer2());
		gameGrid.DisplayGridPuissance4();

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

		Input::InputPuissance4(gameGrid,currentPlayer);
		i++;
	}
	return currentPlayer;
}

//lance la partie
void Puissance4::StartGame() {
	AskGameMode(); //demande le type de jeu
	AskPlayersName();
	Player winner = PlayRound(); //fait jouer les joueurs jusqu'a avoir un gagnant ou égalité

	system("cls");
	Player::DisplayPlayersPuissance4(GetPlayer1(), GetPlayer2());
	gameGrid.DisplayGridPuissance4();
	if (CheckWin(winner)) { cout << "Le joueur " << winner.GetName() << " a gagne" << endl; }
	else if (CheckEquality()) { cout << "Egalite" << endl; }
}

//verifie le cas d'une égalité
bool Puissance4::CheckEquality() const {
	int line = 0;
	int column = 0;

	for (line = 0; line < gameGrid.GetGameGrid().size(); line++)
	{
		for (column = 0; column < gameGrid.GetGameGrid()[0].size(); column++)
		{
			if (gameGrid.GetGameGrid()[line][column].GetOwner() == 0)
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

	for (line = 0; line < gameGrid.GetGameGrid().size(); line++) {

		for (column = 0; column < gameGrid.GetGameGrid()[0].size(); column++) {

			if (gameGrid.GetGameGrid()[line][column].GetOwner() == player.GetId()) {
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

	for (column = 0; column < gameGrid.GetGameGrid()[0].size(); column++) {

		for (line = 0; line < gameGrid.GetGameGrid().size(); line++) {

			if (gameGrid.GetGameGrid()[line][column].GetOwner() == player.GetId()) {
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
	const int gridColumnNumber = gameGrid.GetGameGrid()[0].size() - 1;
	int line = 0;
	int column = 0;
	int totalCount = 0;
	int countDiagonal = 0;

	for (column = 0; column < 4; column++) {

		if (gameGrid.GetGameGrid()[line][column].GetOwner() == player.GetId()) {

			for (countDiagonal = 0; countDiagonal < 4; countDiagonal++) {

				if (gameGrid.GetGameGrid()[line + countDiagonal][column + countDiagonal].GetOwner() == player.GetId()) {
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

				if (gameGrid.GetGameGrid()[line + countDiagonal][gridColumnNumber - column - countDiagonal].GetOwner() == player.GetId()) {
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