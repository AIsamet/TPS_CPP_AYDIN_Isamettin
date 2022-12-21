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
	int round = 0;
	Player currentPlayer;

	while (!CheckWin(currentPlayer) && !CheckEquality())
	{
		currentPlayer = RoundGenerator(round);
		Outputs::DisplayGameMorpion(GetGrid(), GetPlayer1(), GetPlayer2(), currentPlayer);
		Inputs::InputByCell(grid, currentPlayer, grid.GetSize());
		round++;
	}
	return currentPlayer;
}

/**
 * @brief   Lance une partie
 * @return  void
**/
void Morpion::StartGame() {
	AskGameMode(); // demande le type de jeu
	Inputs::InputPlayersNames(player1, player2);
	Player potentialWinner = PlayRound(); // fait jouer les joueurs jusqu'a avoir un gagnant ou égalité
	EndGame(potentialWinner);
}

/**
 * @brief   Termine une partie en affichant le resultat
 * @return  void
**/
void Morpion::EndGame(const Player& PotentialWinner) {
	if (CheckWin(PotentialWinner)) {
		Outputs::DisplayGameResultWinMorpion(GetGrid(), GetPlayer1(), GetPlayer2(), PotentialWinner);
	}
	else if (CheckEquality()) {
		Outputs::DisplayGameResultEqualityMorpion(GetGrid(), GetPlayer1(), GetPlayer2());
	}
}

/**
 * @brief   Verifie s'il y a egalite
 * @return  true s'il y a egalite, false sinon
**/
bool Morpion::CheckEquality() const {
	int cellPosition = 0;

	for (cellPosition = 0; cellPosition < grid.GetSize(); cellPosition++)
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

	for (line = 0; line < grid.GetLineSize(); line++) {

		for (column = 0; column < grid.GetColumnSize(); column++) {

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

	for (column = 0; column < grid.GetColumnSize(); column++) {

		for (line = 0; line < grid.GetLineSize(); line++) {

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