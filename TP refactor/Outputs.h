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
	static void DisplayGameMorpion(const Grid& grid, const Player& player1, const Player& player2, const Player& currentPlayer);
	static void DisplayGamePuissance4(const Grid& grid, const Player& player1, const Player& player2, const Player& currentPlayer);
	static void DisplayGameOthello(const Grid& grid, const Player& player1, const Player& player2, const Player& currentPlayer);

	static void DisplayPlayersMorpion(const Player& player1, const Player& player2);
	static void DisplayPlayersPuissance4(const Player& player1, const Player& player2);
	static void DisplayPlayersOthello(const Player& player1, const Player& player2);

	static void DisplayGridMorpion(const Grid& grid);
	static void DisplayGridPuissance4(const Grid& grid);
	static void DisplayGridOthello(const Grid& grid);

	static string DisplayCellMorpion(const Cell& cell);
	static string DisplayCellPuissance4(const Cell& cell);
	static string DisplayCellOthello(const Cell& cell);

	static string GetRedText(const string& text);
	static string GetGreenText(const string& text);
	static string GetGreyText(const string& text);
	static string GetWhiteText(const string& text);

	static void DisplayInputMessageMorpion(const Player& currentPlayer);
	static void DisplayInputMessagePuissance4(const Player& currentPlayer);
	static void DisplayInputMessageOthello(const Player& currentPlayer);

	static void DisplayGameResultWinMorpion(const Grid& grid, const Player& player1, const Player& player2, const Player& winner);
	static void DisplayGameResultWinPuissance4(const Grid& grid, const Player& player1, const Player& player2, const Player& winner);
	static void DisplayWinMessage(const Player& winner);
	static string GetPlayerNameColored(const Player& player);

	static void DisplayGameResultEqualityMorpion(const Grid& grid, const Player& player1, const Player& player2);
	static void DisplayGameResultEqualityPuissance4(const Grid& grid, const Player& player1, const Player& player2);
	static void DisplayEqualityMessage();

	static void DisplayInputMessagePlayer1Name();
	static void DisplayInputMessagePlayer2Name();

	static void DisplayGameChoices();
	static void DisplayGameModes();

	static void DisplayCellIsNotEmptyErrorMessageMorpion();
	static void DisplayInputtedCellIsNotValid(const int& maxInput);
	static void DisplayColumnIsFullErrorMessagePuissance4();
	static void DisplayInputIsNotValidErrorMessageGameModes();
	static void DisplayInputIsNotNumericErrorMessage();

private:

};

#endif