#ifndef Inputs_h
#define Inputs_h

#include "Game.h"

// Classe fonctionnelle gerant toutes les entrees
class Inputs
{
public:
	/**
	 * Methodes
	**/
	static void InputByCell(Grid& grid, Player& player, const int& maxInput);
	static void InputByColumn(Grid& grid, Player& player, const int& maxInput);

	static void InputByCellPlayer(Grid& grid, Player& player, const int& maxInput);
	static void SetInputByCell(Grid& grid, Player& player, const int& input, const int& maxInput);
	static void SetInputtedCell(Grid& grid, Player& player, const int& input, const int& maxInput);

	static void InputByColumnPlayer(Grid& grid, Player& player, const int& maxInput);
	static void SetInputByColumn(Grid& grid, Player& player, const int& input, const int& maxInput);
	static void SetInputtedColumn(Grid& grid, Player& player, const int& input, const int& maxInput);

	static void InputBotPlayerMorpion(Grid& grid, Player& player);
	static void InputBotPlayerMPuissance4(Grid& grid, Player& player);

	static int BotRandomInputGeneratorMorpion(Grid& grid);
	static int BotRandomInputGeneratorPuissance4(Grid& grid);

	static bool IsNumericInput(const int& input);
	static int GetNumericInput();
	static string GetStringInput();

	static bool IsInputByCellValid(const int& input, const int& maxInput);
	static bool IsInputByColumnValid(const int& input, const int& maxInput);
	static bool IsInputValidGameModes(const int& input);

	static string InputGameChoice();
	static int InputGameMode();

	static void InputPlayersNames(Player& player1, Player& player2);
	static void InputPlayer1Name(Player& player1);
	static void InputPlayer2Name(Player& player2);

private:

};

#endif