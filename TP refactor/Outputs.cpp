#include "Outputs.h"

/**
 * @brief   Affiche le jeu en cours (morpion)
 * @params  grid : la grille de jeu, player1 : joueur 1, player2 : joueur 2 ou IA, currentPlayer : joueur qui doit jouer
 * @return  void
**/
void Outputs::DisplayGameMorpion(const Grid& grid, const Player& player1, const Player& player2, const Player& currentPlayer) {
	system("cls");
	Outputs::DisplayPlayersMorpion(player1, player2);
	Outputs::DisplayGridMorpion(grid);
	Outputs::DisplayInputMessageMorpion(currentPlayer);
}

/**
 * @brief   Affiche le jeu en cours (puissance 4)
 * @params  grid : la grille de jeu, player1 : joueur 1, player2 : joueur 2 ou IA, currentPlayer : joueur qui doit jouer
 * @return  void
**/
void Outputs::DisplayGamePuissance4(const Grid& grid, const Player& player1, const Player& player2, const Player& currentPlayer) {
	system("cls");
	Outputs::DisplayPlayersPuissance4(player1, player2);
	Outputs::DisplayGridPuissance4(grid);
	Outputs::DisplayInputMessagePuissance4(currentPlayer);
}

/**
 * @brief   Affiche le jeu en cours (othello)
 * @params  grid : la grille de jeu, player1 : joueur 1, player2 : joueur 2 ou IA, currentPlayer : joueur qui doit jouer
 * @return  void
**/
void Outputs::DisplayGameOthello(const Grid& grid, const Player& player1, const Player& player2, const Player& currentPlayer) {
	system("cls");
	Outputs::DisplayPlayersOthello(player1, player2);
	Outputs::DisplayGridOthello(grid, currentPlayer);
	Outputs::DisplayInputMessageOthello(currentPlayer);
}

/**
 * @brief   Affiche les joueurs (morpion)
 * @params  player1 : joueur 1, player2 : joueur 2 ou IA
 * @return  void
**/
void Outputs::DisplayPlayersMorpion(const Player& player1, const Player& player2) {
	cout << GetRedText("Joueur " + player1.GetName() + " (X)") << "  -  " << GetGreenText("Joueur " + player2.GetName() + " (O)") << endl << endl;
}

/**
 * @brief   Affiche les joueurs (puissance 4)
 * @params  player1 : joueur 1, player2 : joueur 2 ou IA
 * @return  void
**/
void Outputs::DisplayPlayersPuissance4(const Player& player1, const Player& player2) {
	cout << GetRedText("Joueur " + player1.GetName()) << "  -  " << GetGreenText("Joueur " + player2.GetName()) << endl << endl;
}

/**
 * @brief   Affiche les joueurs (othello)
 * @params  player1 : joueur 1, player2 : joueur 2 ou IA
 * @return  void
**/
void Outputs::DisplayPlayersOthello(const Player& player1, const Player& player2) {
	cout << GetRedText("Joueur " + player1.GetName()) << "  -  " << GetGreenText("Joueur " + player2.GetName()) << endl;
}

/**
 * @brief   Affiche la grille de jeu (morpion)
 * @return  void
**/
void Outputs::DisplayGridMorpion(const Grid& grid) {
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << DisplayCellMorpion(grid.GetCell(0)) << "  |  " << DisplayCellMorpion(grid.GetCell(1)) << "  |  " << DisplayCellMorpion(grid.GetCell(2)) << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << DisplayCellMorpion(grid.GetCell(3)) << "  |  " << DisplayCellMorpion(grid.GetCell(4)) << "  |  " << DisplayCellMorpion(grid.GetCell(5)) << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << DisplayCellMorpion(grid.GetCell(6)) << "  |  " << DisplayCellMorpion(grid.GetCell(7)) << "  |  " << DisplayCellMorpion(grid.GetCell(8)) << endl;

	cout << "     |     |     " << endl << endl;
}

/**
 * @brief   Affiche la grille de jeu (puissance 4)
 * @return  void
**/
void Outputs::DisplayGridPuissance4(const Grid& grid) {
	cout << endl;

	cout << "|  " << "1" << "  |  " << "2" << "  |  " << "3" << "  |  " << "4" << "  |  " << "5" << "  |  " << "6" << "  |  " << "7" << "  |  " << endl;


	cout << " _________________________________________" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;
	cout << "|  " << DisplayCellPuissance4(grid.GetCell(21)) << "  |  " << DisplayCellPuissance4(grid.GetCell(22)) << "  |  " << DisplayCellPuissance4(grid.GetCell(23)) << "  |  " << DisplayCellPuissance4(grid.GetCell(24)) << "  |  " << DisplayCellPuissance4(grid.GetCell(25)) << "  |  " << DisplayCellPuissance4(grid.GetCell(26)) << "  |  " << DisplayCellPuissance4(grid.GetCell(27)) << "  |  " << endl;

	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;

	cout << "|  " << DisplayCellPuissance4(grid.GetCell(14)) << "  |  " << DisplayCellPuissance4(grid.GetCell(15)) << "  |  " << DisplayCellPuissance4(grid.GetCell(16)) << "  |  " << DisplayCellPuissance4(grid.GetCell(17)) << "  |  " << DisplayCellPuissance4(grid.GetCell(18)) << "  |  " << DisplayCellPuissance4(grid.GetCell(19)) << "  |  " << DisplayCellPuissance4(grid.GetCell(20)) << "  |  " << endl;

	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;

	cout << "|  " << DisplayCellPuissance4(grid.GetCell(7)) << "  |  " << DisplayCellPuissance4(grid.GetCell(8)) << "  |  " << DisplayCellPuissance4(grid.GetCell(9)) << "  |  " << DisplayCellPuissance4(grid.GetCell(10)) << "  |  " << DisplayCellPuissance4(grid.GetCell(11)) << "  |  " << DisplayCellPuissance4(grid.GetCell(12)) << "  |  " << DisplayCellPuissance4(grid.GetCell(13)) << "  |  " << endl;

	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
	cout << "|     |     |     |     |     |     |     |" << endl;

	cout << "|  " << DisplayCellPuissance4(grid.GetCell(0)) << "  |  " << DisplayCellPuissance4(grid.GetCell(1)) << "  |  " << DisplayCellPuissance4(grid.GetCell(2)) << "  |  " << DisplayCellPuissance4(grid.GetCell(3)) << "  |  " << DisplayCellPuissance4(grid.GetCell(4)) << "  |  " << DisplayCellPuissance4(grid.GetCell(5)) << "  |  " << DisplayCellPuissance4(grid.GetCell(6)) << "  |  " << endl;
	cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl << endl;
}

/**
 * @brief   Affiche la grille de jeu (othello)
 * @return  void
**/
void Outputs::DisplayGridOthello(const Grid& grid, const Player& currentPlayer) {
	cout << endl;

	cout << " _______________________________________________" << endl;
	cout << "|     |     |     |     |     |     |     |     |" << endl;

	string line;
	int idCell = 0;
	for (int i = 0; i < 8; i++)
	{
		line = "";
		for (int j = 0; j < 8; j++)
		{
			if (j == 0)
			{
				line += "|  ";
			}
			if ((grid.GetCell(idCell).GetIdCell() < 9) && (grid.IsCellFree(idCell)) && (Checks::IsOthelloCellPlayable(grid, currentPlayer, idCell))) {
				line += DisplayCellOthello(grid.GetCell(idCell)) + "  |  ";
			}
			else if ((grid.GetCell(idCell).GetIdCell() > 8) && (grid.IsCellFree(idCell)) && (Checks::IsOthelloCellPlayable(grid, currentPlayer, idCell))) {
				line += DisplayCellOthello(grid.GetCell(idCell)) + " |  ";
			}
			else if ((grid.GetCell(idCell).GetIdCell() < 10) && (grid.IsCellFree(idCell))){
				line += "   |  ";
			}
			else if ((grid.GetCell(idCell).GetIdCell() > 9) && (grid.IsCellFree(idCell))){
				line += "   |  ";
			}
			else if (!grid.IsCellFree(idCell)) {
				line += DisplayCellOthello(grid.GetCell(idCell)) + "  |  ";
			}
			idCell++;
		}
		cout << line << endl;
		if (i < 7)
		{
			cout << "|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
			cout << "|     |     |     |     |     |     |     |     |" << endl;
		}
		else
		{
			cout << "|_____|_____|_____|_____|_____|_____|_____|_____|" << endl << endl;
		}
	}
}

/**
 * @brief   Genere l'affichage d'une case pour le jeu de morpion
 * @return  idCell par defaut sinon X rouge pour le joueur 1, O vert pour le joueur 2
**/
string Outputs::DisplayCellMorpion(const Cell& cell) {
	string str = to_string(cell.GetIdCell()+1);
	if (cell.GetOwner() == 1) {
		str = GetRedText("X");
	}
	else if (cell.GetOwner() == 2) {
		str = GetGreenText("O");
	}
	return str;
}

/**
 * @brief   Genere l'affichage d'une case pour le jeu de puissance 4
 * @return  chaîne vide par defaut sinon O rouge pour le joueur 1, O vert pour le joueur 2
**/
string Outputs::DisplayCellPuissance4(const Cell& cell) {
	string str = " ";
	if (cell.GetOwner() == 1) {
		str = GetRedText("O");
	}
	else if (cell.GetOwner() == 2) {
		str = GetGreenText("O");
	}
	return str;
}

/**
 * @brief   Genere l'affichage d'une case pour le jeu d'othello
 * @return  chaîne vide par defaut sinon O rouge pour le joueur 1, O vert pour le joueur 2
**/
string Outputs::DisplayCellOthello(const Cell& cell) {
	string str = to_string(cell.GetIdCell()+1);
	if (cell.GetOwner() == 1) {
		str = GetRedText("O");
	}
	else if (cell.GetOwner() == 2) {
		str = GetGreenText("O");
	}
	return str;
}

/**
 * @brief   Permet de retourner du texte en rouge
 * @params  text : texte que l'on souhaite colorer
 * @return  le texte dans la bonne couleur
**/
string Outputs::GetRedText(const string& text) {
	return "\033[1;31m" + text + "\033[0m";
}

/**
 * @brief   Permet de retourner du texte en vert
 * @params  text : texte que l'on souhaite colorer
 * @return  le texte dans la bonne couleur
**/
string Outputs::GetGreenText(const string& text) {
	return "\033[1;32m" + text + "\033[0m";
}

string Outputs::GetGreyText(const string& text) {
	return "\033[1;30m" + text + "\033[0m";
}

string Outputs::GetWhiteText(const string& text) {
	return "\033[1;37m" + text + "\033[0m";
}

/**
 * @brief   Affiche le message de demande d'entrée joueur (morpion)
 * @params  player : joueur qui doit jouer
 * @return  void
**/
void Outputs::DisplayInputMessageMorpion(const Player& player) {
	if (player.GetId() == 1) {
		cout << "Tour " << GetRedText("joueur " + player.GetName()) << ", dans quelle case voulez - vous jouer ? " << endl;
	}
	else {
		if (player.GetIsBot() == 0) {
			cout << "Tour " << GetGreenText("joueur " + player.GetName()) << ", dans quelle case voulez - vous jouer ? " << endl;
		}
		else {
			cout << "Le " << GetGreenText("joueur " + player.GetName()) << " joue son tour" << endl;
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
}

/**
 * @brief   Affiche le message de demande d'entrée joueur (puissance 4)
 * @params  player : joueur qui doit jouer
 * @return  void
**/
void Outputs::DisplayInputMessagePuissance4(const Player& player) {
	if (player.GetId() == 1) {
		cout << "Tour " << GetRedText("joueur " + player.GetName()) << ", dans quelle colonne voulez - vous jouer ? " << endl;
	}
	else {
		if (player.GetIsBot() == 0) {
			cout << "Tour " << GetGreenText("joueur " + player.GetName()) << ", dans quelle colonne voulez - vous jouer ? " << endl;
		}
		else {
			cout << "Le " << GetGreenText("joueur " + player.GetName()) << " joue son tour" << endl;
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
}

/**
 * @brief   Affiche le message de demande d'entrée joueur (othello)
 * @params  player : joueur qui doit jouer
 * @return  void
**/
void Outputs::DisplayInputMessageOthello(const Player& player) {
	if (player.GetId() == 1) {
		cout << "Tour " << GetRedText("joueur " + player.GetName()) << ", dans quelle case voulez - vous jouer ? " << endl;
	}
	else {
		if (player.GetIsBot() == 0) {
			cout << "Tour " << GetGreenText("joueur " + player.GetName()) << ", dans quelle case voulez - vous jouer ? " << endl;
		}
		else {
			cout << "Le " << GetGreenText("joueur " + player.GetName()) << " joue son tour" << endl;
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
}

/**
 * @brief   Affiche le resultat du jeu en cas de victoire (mropion)
 * @params  grid : la grille de jeu, player1 : joueur 1, player2 : joueur 2 ou IA, winner : le gagnant
 * @return  void
**/
void Outputs::DisplayGameResultWinMorpion(const Grid& grid, const Player& player1, const Player& player2, const Player& winner) {
	system("cls");
	Outputs::DisplayPlayersMorpion(player1, player2);
	Outputs::DisplayGridMorpion(grid);
	Outputs::DisplayWinMessage(winner);
}

/**
 * @brief   Affiche le resultat du jeu en cas de victoire (puissance 4)
 * @params  grid : la grille de jeu, player1 : joueur 1, player2 : joueur 2 ou IA, winner : le gagnant
 * @return  void
**/
void Outputs::DisplayGameResultWinPuissance4(const Grid& grid, const Player& player1, const Player& player2, const Player& winner) {
	system("cls");
	Outputs::DisplayPlayersPuissance4(player1, player2);
	Outputs::DisplayGridPuissance4(grid);
	Outputs::DisplayWinMessage(winner);

}

/**
 * @brief   Affiche un message en cas de victoire
 * @params  winner : le gagnant
 * @return  void
**/
void Outputs::DisplayWinMessage(const Player& Winner) {
	cout << "Le joueur " << GetPlayerNameColored(Winner) << " a gagne" << endl;
}

string Outputs::GetPlayerNameColored(const Player& player) {
	if (player.GetId() == 1)
	{
		return Outputs::GetRedText(player.GetName());
	}
	else
	{
		return Outputs::GetGreenText(player.GetName());
	}
}

/**
 * @brief   Affiche le resultat du jeu en cas d'égalité (morpion)
 * @params  grid : la grille de jeu, player1 : joueur 1, player2 : joueur 2 ou IA
 * @return  void
**/
void Outputs::DisplayGameResultEqualityMorpion(const Grid& grid, const Player& player1, const Player& player2) {
	system("cls");
	Outputs::DisplayPlayersMorpion(player1, player2);
	Outputs::DisplayGridMorpion(grid);
	DisplayEqualityMessage();
}

/**
 * @brief   Affiche le resultat du jeu en cas d'égalité (puissance 4)
 * @params  grid : la grille de jeu, player1 : joueur 1, player2 : joueur 2 ou IA
 * @return  void
**/
void Outputs::DisplayGameResultEqualityPuissance4(const Grid& grid, const Player& player1, const Player& player2) {
	system("cls");
	Outputs::DisplayPlayersPuissance4(player1, player2);
	Outputs::DisplayGridPuissance4(grid);
	DisplayEqualityMessage();
}

/**
 * @brief   Affiche un message en cas d'égalité
 * @return  void
**/
void Outputs::DisplayEqualityMessage() {
	cout << "Le jeu se termine sur une egalite" << endl;
}

/**
 * @brief   Affiche un message d'entrée pour les noms de joueurs
 * @return  void
**/
void Outputs::DisplayInputMessagePlayer1Name() {
	system("cls");
	cout << "Entrez le nom du joueur 1" << endl;
	cout << "-> ";
}

void Outputs::DisplayInputMessagePlayer2Name() {
	cout << "\nEntrez le nom du joueur 2" << endl;
	cout << "-> ";
}

void Outputs::DisplayGameChoices() {
	cout << "1. Puissance 4" << endl;
	cout << "2. Morpion" << endl;
	cout << "3. Othello" << endl;
	cout << "4. Quitter" << endl << endl;
	cout << "Choix : ";
}

void Outputs::DisplayGameModes() {
	cout << "\nA quelle mode de jeu voulez vous jouer ? " << endl;
	cout << "1 - Joueur contre Joueur" << endl;
	cout << "2 - Joueur contre IA" << endl << endl;
	cout << "Choix : ";
}

/**
 * @brief   Diffrerents messages d'erreur
 * @return  void
**/
void Outputs::DisplayCellIsNotEmptyErrorMessageMorpion() {
	cout << "La case est deja occupee, veuillez choisir une autre case" << endl;
}

void Outputs::DisplayInputtedCellIsNotValid(const int& maxInput) {
	cout << "Veuillez saisir un chiffre entre 1 et " << maxInput << endl;
}

void Outputs::DisplayInputtedCellIsNotValidOthello() {
	cout << "Veuillez saisir une case valide" << endl;
}

void Outputs::DisplayColumnIsFullErrorMessagePuissance4() {
	cout << "La colonne est pleine, veuillez choisir une autre colonne" << endl;
}

void Outputs::DisplayInputIsNotValidErrorMessageGameModes() {
	system("cls");
	cout << "Veuillez saisir un choix valide" << endl;
}

void Outputs::DisplayInputIsNotNumericErrorMessage() {
	cout << "Veuillez entrer un chiffre" << endl;
}

