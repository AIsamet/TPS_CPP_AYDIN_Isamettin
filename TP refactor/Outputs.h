#ifndef Outputs_h
#define Outputs_h

#include "Game.h"

// Classe fonctionnelle gerant toutes les sorties
class Outputs
{
public:
	/**
	 * Methodes
	**/
	static string GetRedText(const string& text);
	static string GetGreenText(const string& text);

	static void DisplayGamePuissance4(const Grid& grid, const Player& player1, const Player& player2, const Player& currentPlayer);
	static void DisplayGameMorpion(const Grid& grid, const Player& player1, const Player& player2, const Player& currentPlayer);

	static void DisplayGameResultWinnerPuissance4(const Grid& grid, const Player& player1, const Player& player2, const Player& winner);
	static void DisplayGameResultWinnerMorpion(const Grid& grid, const Player& player1, const Player& player2, const Player& winner);

	static void DisplayGameResultEqualityPuissance4(const Grid& grid, const Player& player1, const Player& player2);
	static void DisplayGameResultEqualityMorpion(const Grid& grid, const Player& player1, const Player& player2);

	static void DisplayWinMessage(const Player& Winner);
	static void DisplayEqualityMessage();

	static void DisplayGridMorpion(const Grid& grid);
	static void DisplayGridPuissance4(const Grid& grid);

	static string DisplayCellMorpion(const Cell& cell);
	static string DisplayCellPuissance4(const Cell& cell);

	static void DisplayPlayersMorpion(const Player& player1, const Player& player2);
	static void DisplayPlayersPuissance4(const Player& player1, const Player& player2);

	static void DisplayInputMessagePuissance4(const Player& currentPlayer);
	static void DisplayInputMessageMorpion(const Player& currentPlayer);


private:

};

#endif