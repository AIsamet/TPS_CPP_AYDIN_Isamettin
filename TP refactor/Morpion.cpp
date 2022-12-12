#include "Morpion.h"

/**
 * @brief   Construit un nouveau jeu de morpion
 * @params  player1Name : nom du joueur 1, player2Name : nom du joueur 2 ou IA
**/
Morpion::Morpion() {
	grid = Grid(3, 3);
	player1 = Player(1, "A");
	player2 = Player(2, "B");
}

/**
 * @brief   Lance un tour jusqu'a ce qu'il y ait victoire ou egalite
 * @return  joueur actuel
**/
Player Morpion::PlayRound() {
	int i = 0;
	Player currentPlayer = player1;

	while (!CheckWin(currentPlayer) && !CheckEquality())
	{
		system("cls");
		Player::DisplayPlayersMorpion(GetPlayer1(), GetPlayer2());
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

/**
 * @brief   Lance une partie
 * @return  void
**/
void Morpion::StartGame() {

	AskGameMode(); // demande le type de jeu
	AskPlayersNames();
	Player winner = PlayRound(); // fait jouer les joueurs jusqu'a avoir un gagnant ou égalité

	system("cls");
	Player::DisplayPlayersMorpion(GetPlayer1(), GetPlayer2());
	grid.DisplayGridMorpion();
	if (CheckWin(winner)) { cout << "Le joueur " << winner.GetName() << " a gagne" << endl; }
	else if (CheckEquality()) { cout << "Egalite" << endl; }
}

/**
 * @brief   Verifie s'il y a egalite
 * @return  true s'il y a egalite, false sinon
**/
bool Morpion::CheckEquality() const {
	int cellPosition = 0;
	
	for (cellPosition = 0; cellPosition < grid.GetGameGrid().size(); cellPosition++)
	{
		if (grid.GetCell(cellPosition).GetOwner() == 0)
		{
			return false;
		}
	}
	return true;
}

/**
 * @brief   Verifie si un joueur a gagne
 * @param   player : joueur
 * @return  true si le joueur a gagne, false sinon
**/
bool Morpion::CheckWin(const Player& player) const {
	return CheckWinByLine(player) || CheckWinByColumn(player) || CheckWinByDiagonal(player);
}

/**
 * @brief   Verifie si un joueur a gagne en ligne
 * @param   player : joueur
 * @return  true si le joueur a gagne en ligne, false sinon
**/
bool Morpion::CheckWinByLine(const Player& player) const {
	int line = 0;
	int column = 0;
	int count = 0;

	for (line = 0; line < grid.GetLine(); line++) {

		for (column = 0; column < grid.GetColumn(); column++) {

			if (grid.GetCell(line, column).GetOwner() == player.GetId()) {
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

/**
 * @brief   Verifie si un joueur a gagne en colonne
 * @param   player : joueur
 * @return  true si le joueur a gagne en colonne, false sinon
**/
bool Morpion::CheckWinByColumn(const Player& player) const {
	int line = 0;
	int column = 0;
	int count = 0;

	for (column = 0; column < grid.GetColumn(); column++) {

		for (line = 0; line < grid.GetLine(); line++) {

			if (grid.GetCell(line, column).GetOwner() == player.GetId()) {
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

/**
 * @brief   Verifie si un joueur a gagne en diagonale
 * @param   player : joueur
 * @return  true si le joueur a gagne en diagonale, false sinon
**/
bool Morpion::CheckWinByDiagonal(const Player& player) const {
	int line = 0;
	int column = 0;
	int countAsc = 0;
	int countDesc = 0;

	for (line = 0; line < 3; line++) {

		if (grid.GetCell(line, line).GetOwner() == player.GetId()) {
			countAsc++;
		}
		if (grid.GetCell(line, 2 - line).GetOwner() == player.GetId()) {
			countDesc++;
		}
	}
	if (countAsc == 3 || countDesc == 3) {
		return true;
	}
	return false;
}