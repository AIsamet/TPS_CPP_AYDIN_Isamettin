#include "Puissance4.h"

/**
 * @brief   Construit un nouveau jeu de puissance 4
**/
Puissance4::Puissance4() {
	grid = Grid(4, 7);
	player1 = Player(1, "A");
	player2 = Player(2, "B");
}

/**
 * @brief   Lance un tour jusqu'a ce qu'il y ait victoire ou egalite
 * @return  joueur actuel
**/
Player Puissance4::PlayRound() {
	int round = 0;
	Player currentPlayer;

	while (!CheckWin(currentPlayer) && !CheckEquality())
	{
		currentPlayer = RoundGenerator(round);
		Outputs::DisplayGamePuissance4(GetGrid(), GetPlayer1(), GetPlayer2(), currentPlayer);
		Inputs::InputPuissance4(grid, currentPlayer);
		round++;
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
	Player potentialWinner = PlayRound(); // fait jouer les joueurs jusqu'a avoir un gagnant ou égalité
	EndGame(potentialWinner);
}

/**
 * @brief   Termine une partie en affichant le resultat
 * @return  void
**/
void Puissance4::EndGame(const Player& PotentialWinner) {
	if (CheckWin(PotentialWinner)) {
		Outputs::DisplayGameResultWinnerPuissance4(GetGrid(), GetPlayer1(), GetPlayer2(), PotentialWinner);
	}
	else if (CheckEquality()) {
		Outputs::DisplayGameResultEqualityPuissance4(GetGrid(), GetPlayer1(), GetPlayer2());
	}
}

/**
 * @brief   Verifie s'il y a egalite
 * @return  true s'il y a egalite, false sinon
**/
bool Puissance4::CheckEquality() const {
	int cellPosition = 0;

	for (cellPosition = 0; cellPosition < grid.GetGameGrid().size(); cellPosition++)
	{
		if (grid.GetGameGrid()[cellPosition].GetOwner() == 0)
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

	for (line = 0; line < grid.GetLine(); line++) {

		for (column = 0; column < grid.GetColumn(); column++) {

			if (grid.GetCell(line, column).GetOwner() == player.GetId()) {
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

	for (column = 0; column < grid.GetColumn(); column++) {

		for (line = 0; line < grid.GetLine(); line++) {

			if (grid.GetCell(line, column).GetOwner() == player.GetId()) {
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
	const int gridColumnNumber = grid.GetColumn() - 1;
	int line = 0;
	int column = 0;
	int totalCount = 0;
	int countDiagonal = 0;

	for (column = 0; column < 4; column++) {

		if (grid.GetCell(line, column).GetOwner() == player.GetId()) {

			for (countDiagonal = 0; countDiagonal < 4; countDiagonal++) {

				if (grid.GetCell(line + countDiagonal, column + countDiagonal).GetOwner() == player.GetId()) {
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

				if (grid.GetCell(line + countDiagonal, gridColumnNumber - column - countDiagonal).GetOwner() == player.GetId()) {
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