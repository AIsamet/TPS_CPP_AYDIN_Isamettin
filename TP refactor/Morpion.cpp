#include "Morpion.h"

Morpion::Morpion() {
	grid = Grid(3, 3);
	player1 = Player(1, "A");
	player2 = Player(2, "B");
}

Morpion::Morpion(string player1Name, string player2Name) {
	grid = Grid(3, 3);
	player1 = Player(1, "A");
	player2 = Player(2, "B");
}

//fait jouer les tours des joueurs jusqu'a ce qu'il y ait un gagnant ou égalité
Player Morpion::PlayRound() {
	int i = 0;
	Player currentPlayer = player1;

	while (!CheckWin(currentPlayer) && !CheckEquality())
	{
		system("cls");
		Player::DisplayPlayersPuissance4(GetPlayer1(), GetPlayer2());
		grid.DisplayGridMorpion();

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

		Inputs::InputMorpion(grid, currentPlayer);
		i++;
	}
	return currentPlayer;
}

//lance la partie
void Morpion::StartGame() {

	AskGameMode(); //demande le type de jeu
	AskPlayersNames();
	Player winner = PlayRound(); //fait jouer les joueurs jusqu'a avoir un gagnant ou égalité
	
	system("cls");
	Player::DisplayPlayersMorpion(GetPlayer1(), GetPlayer2());
	grid.DisplayGridMorpion();
	if (CheckWin(winner)) { cout << "Le joueur " << winner.GetName() << " a gagne" << endl; }
	else if (CheckEquality()) { cout << "Egalite" << endl; }
}

//verifie le cas d'une égalité
bool Morpion::CheckEquality() const {
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

	for (line = 0; line < grid.GetGameGrid().size(); line++) {

		for (column = 0; column < grid.GetGameGrid()[0].size(); column++) {

			if (grid.GetGameGrid()[line][column].GetOwner() == player.GetId()) {
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

	for (column = 0; column < grid.GetGameGrid()[0].size(); column++) {

		for (line = 0; line < grid.GetGameGrid().size(); line++) {

			if (grid.GetGameGrid()[line][column].GetOwner() == player.GetId()) {
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

		if (grid.GetGameGrid()[line][line].GetOwner() == player.GetId()) {
			count++;
		}
		if (grid.GetGameGrid()[line][2 - line].GetOwner() == player.GetId()) {
			countBis++;
		}
	}
	if (count == 3 || countBis == 3) {
		return true;
	}
	return false;
}