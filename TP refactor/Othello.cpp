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
		FlipCellsByDiagonal(currentPlayer);
		FlipCellsByLine(currentPlayer);
		FlipCellsByColumn(currentPlayer);
		currentPlayer = RoundGenerator(round);
		Outputs::DisplayGameOthello(GetGrid(), GetPlayer1(), GetPlayer2(), currentPlayer);
		Inputs::InputOthello(grid, currentPlayer, grid.GetSize());
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

void Othello::FlipCellsByLine(const Player& player) {
	vector<Cell> cellsToFlip;
	bool flipCells = false;

	for (int line = 0; line < grid.GetLineSize(); line++)
	{
		for (int column = 0; column < grid.GetColumnSize(); column++)
		{
			// debut du parcours de la prise en sandwich
			if (grid.GetCellOwner(line, column) == player.GetId() && !flipCells)
			{
				flipCells = true;
			}
			// fin du parcours de la prise en sandwich => on retourne les pions
			else if (grid.GetCellOwner(line, column) == player.GetId() && flipCells)
			{
				for (auto cellToFlip : cellsToFlip)
				{
					grid.FlipCell(player.GetId(), cellToFlip.GetIdCell());
				}
				flipCells = false;
				cellsToFlip.clear();
			}
			// s'il s'agit d'une cellule vide ou qu'on est arrive en bout de ligne => on annule la prise en sandwich
			else if ((grid.IsCellFree(line, column) || column == 7) && flipCells)
			{
				flipCells = false;
				cellsToFlip.clear();
			}
			// s'il s'agit d'une cellule appartenant au joueur adverse => on recupere la cellule
			else if (grid.GetCellOwner(line, column) != player.GetId() && flipCells)
			{
				cellsToFlip.push_back(grid.GetCell(line, column));
			}
		}
	}
}

void Othello::FlipCellsByColumn(const Player& player) {
	vector<Cell> cellsToFlip;
	bool flipCells = false;

	for (int column = 0; column < grid.GetColumnSize(); column++)
	{
		for (int line = 0; line < grid.GetLineSize(); line++)
		{
			// debut du parcours de la prise en sandwich
			if (grid.GetCellOwner(line, column) == player.GetId() && !flipCells)
			{
				flipCells = true;
			}
			// fin du parcours de la prise en sandwich => on retourne les pions
			else if (grid.GetCellOwner(line, column) == player.GetId() && flipCells)
			{
				for (auto cellToFlip : cellsToFlip)
				{
					grid.FlipCell(player.GetId(), cellToFlip.GetIdCell());
				}
				flipCells = false;
				cellsToFlip.clear();
			}
			// s'il s'agit d'une cellule vide ou qu'on est arrive en bout de colonne => on annule la prise en sandwich
			else if ((grid.IsCellFree(line, column) || line == 7) && flipCells)
			{
				flipCells = false;
				cellsToFlip.clear();
			}
			// s'il s'agit d'une cellule appartenant au joueur adverse => on recupere la cellule
			else if (grid.GetCellOwner(line, column) != player.GetId() && flipCells)
			{
				cellsToFlip.push_back(grid.GetCell(line, column));
			}
		}
	}
}

void Othello::FlipCellsByDiagonal(const Player& player) {
	vector<Cell> cellsToFlip;
	bool flipCells = false;

	for (int n = -grid.GetLineSize(); n <= grid.GetLineSize(); n++) {
		for (int i = 0; i < grid.GetLineSize(); i++) {
			if ((i - n >= 0) && (i - n < grid.GetLineSize())) {
				// debut du parcours de la prise en sandwich
				if (grid.GetCellOwner(i, i - n) == player.GetId() && !flipCells)
				{
					flipCells = true;
				}
				// fin du parcours de la prise en sandwich => on retourne les pions
				else if (grid.GetCellOwner(i, i - n) == player.GetId() && flipCells)
				{
					for (auto cellToFlip : cellsToFlip)
					{
						grid.FlipCell(player.GetId(), cellToFlip.GetIdCell());
					}
					flipCells = false;
					cellsToFlip.clear();
				}
				// s'il s'agit d'une cellule vide ou qu'on est arrive en bout de colonne => on annule la prise en sandwich
				else if ((grid.IsCellFree(i, i - n) || i == 7) && flipCells)
				{
					flipCells = false;
					cellsToFlip.clear();
				}
				// s'il s'agit d'une cellule appartenant au joueur adverse => on recupere la cellule
				else if (grid.GetCellOwner(i, i - n) != player.GetId() && flipCells)
				{
					cellsToFlip.push_back(grid.GetCell(i, i - n));
				}
			}
		}
	}
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