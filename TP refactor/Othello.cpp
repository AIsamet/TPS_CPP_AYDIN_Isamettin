#include "Othello.h"

/**
 * @brief   Construit un nouveau jeu de morpion
 * @params  player1Name : nom du joueur 1, player2Name : nom du joueur 2 ou IA
**/
Othello::Othello() {
	grid = Grid(8, 8);
	player1 = Player(1, "A");
	player2 = Player(2, "B");

	// position de depart pour le jeu d'othello
	grid.SetCellOwnerIfEmpty(27, 2);
	grid.SetCellOwnerIfEmpty(28, 1);
	grid.SetCellOwnerIfEmpty(35, 1);
	grid.SetCellOwnerIfEmpty(36, 2);
}

/**
 * @brief   Lance un tour jusqu'a ce qu'il y ait victoire ou egalite
 * @return  joueur actuel
**/
Player Othello::PlayRound() {
	int round = 0;
	Player currentPlayer;

	while (!CheckWin(currentPlayer) && !CheckEquality())
	{
		currentPlayer = RoundGenerator(round);
		Outputs::DisplayGameOthello(GetGrid(), GetPlayer1(), GetPlayer2(), currentPlayer);
		Inputs::InputByCell(grid, currentPlayer, grid.GetSize());
		round++;
	}

	return currentPlayer;
}

/**
 * @brief   Lance une partie
 * @return  void
**/
void Othello::StartGame() {
	AskGameMode(); // demande le type de jeu
	Inputs::InputPlayersNames(player1, player2);
	Player potentialWinner = PlayRound(); // fait jouer les joueurs jusqu'a avoir un gagnant ou égalité
	EndGame(potentialWinner);
}

/**
 * @brief   Termine une partie en affichant le resultat
 * @return  void
**/
void Othello::EndGame(const Player& PotentialWinner) {

}

/**
 * @brief   Verifie s'il y a egalite
 * @return  true s'il y a egalite, false sinon
**/
bool Othello::CheckEquality() const {

	return false;
}

/**
 * @brief   Verifie si un joueur a gagne
 * @param   player : joueur
 * @return  true si le joueur a gagne, false sinon
**/
bool Othello::CheckWin(const Player& player) const {
	return CheckWinByLine(player) || CheckWinByColumn(player) || CheckWinByDiagonal(player);
}

/**
 * @brief   Verifie si un joueur a gagne en ligne
 * @param   player : joueur
 * @return  true si le joueur a gagne en ligne, false sinon
**/
bool Othello::CheckWinByLine(const Player& player) const {

	return false;
}

/**
 * @brief   Verifie si un joueur a gagne en colonne
 * @param   player : joueur
 * @return  true si le joueur a gagne en colonne, false sinon
**/
bool Othello::CheckWinByColumn(const Player& player) const {

	return false;
}

/**
 * @brief   Verifie si un joueur a gagne en diagonale
 * @param   player : joueur
 * @return  true si le joueur a gagne en diagonale, false sinon
**/
bool Othello::CheckWinByDiagonal(const Player& player) const {

	return false;
}
