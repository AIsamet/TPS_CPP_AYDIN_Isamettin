#include "Outputs.h"

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

/**
 * @brief   Genere l'affichage d'une case pour le jeu de morpion
 * @return  idCell par defaut sinon X pour le joueur 1, O pour le joueur 2
**/
string Outputs::DisplayCellMorpion(const Cell& cell) {
	string str = to_string(cell.GetIdCell());
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
 * @brief   Affiche les joueurs (morpion)
 * @params  player1 : joueur 1, player2 : joueur 2 ou IA
 * @return  void
**/
void Outputs::DisplayPlayersMorpion(const Player& player1, const Player& player2)
{
	cout << "\033[1;31mJoueur " << player1.GetName() << " (X)\033[0m  -  \033[1;32mJoueur " << player2.GetName() << " (O)\033[0m" << endl << endl;
}

/**
 * @brief   Affiche les joueurs (puissance 4)
 * @params  player1 : joueur 1, player2 : joueur 2 ou IA
 * @return  void
**/
void Outputs::DisplayPlayersPuissance4(const Player& player1, const Player& player2)
{
	cout << GetRedText("Joueur " + player1.GetName()) << "  -  " << GetGreenText("Joueur " + player2.GetName()) << endl << endl;
}


void Outputs::DisplayInputMessagePuissance4(const Player& player)
{
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

void Outputs::DisplayInputMessageMorpion(const Player& player)
{
	if (player.GetId() == 1) {
		cout << "Tour " << GetRedText("joueur" + player.GetName()) << ", dans quelle case voulez - vous jouer ? " << endl;
	}
	else {
		if (player.GetIsBot() == 0) {
			cout << "Tour " << GetGreenText("joueur" + player.GetName()) << ", dans quelle case voulez - vous jouer ? " << endl;
		}
		else {
			cout << "Le " << GetGreenText("joueur" + player.GetName()) << " joue son tour" << endl;
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
}


void Outputs::DisplayGamePuissance4(const Grid& grid, const Player& player1, const Player& player2, const Player& currentPlayer)
{
	system("cls");
	Outputs::DisplayPlayersPuissance4(player1, player2);
	Outputs::DisplayGridPuissance4(grid);
	Outputs::DisplayInputMessagePuissance4(currentPlayer);
}

void Outputs::DisplayGameMorpion(const Grid& grid, const Player& player1, const Player& player2, const Player& currentPlayer)
{
	system("cls");
	Outputs::DisplayPlayersMorpion(player1, player2);
	Outputs::DisplayGridMorpion(grid);
	Outputs::DisplayInputMessageMorpion(currentPlayer);
}


void Outputs::DisplayGameResultWinnerPuissance4(const Grid& grid, const Player& player1, const Player& player2, const Player& winner)
{
	system("cls");
	Outputs::DisplayPlayersPuissance4(player1, player2);
	Outputs::DisplayGridPuissance4(grid);
	Outputs::DisplayWinMessage(winner);

}

void Outputs::DisplayGameResultWinnerMorpion(const Grid& grid, const Player& player1, const Player& player2, const Player& winner)
{
	system("cls");
	Outputs::DisplayPlayersMorpion(player1, player2);
	Outputs::DisplayGridMorpion(grid);
	Outputs::DisplayWinMessage(winner);

}


void Outputs::DisplayGameResultEqualityPuissance4(const Grid& grid, const Player& player1, const Player& player2)
{
	system("cls");
	Outputs::DisplayPlayersPuissance4(player1, player2);
	Outputs::DisplayGridPuissance4(grid);
	DisplayEqualityMessage();
}

void Outputs::DisplayGameResultEqualityMorpion(const Grid& grid, const Player& player1, const Player& player2)
{
	system("cls");
	Outputs::DisplayPlayersMorpion(player1, player2);
	Outputs::DisplayGridMorpion(grid);
	DisplayEqualityMessage();
}


void Outputs::DisplayWinMessage(const Player& Winner)
{
	cout << "Le joueur " << Winner.GetName() << " a gagne" << endl;
}

void Outputs::DisplayEqualityMessage()
{
	cout << "Le jeu se termine sur une egalite" << endl;
}