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
	static void InputMorpion(Grid& grid, Player& player);
	static void InputPuissance4(Grid& grid, Player& player);
	static void InputOthello(Grid& grid, Player& player);

	static void InputPlayerMorpion(Grid& grid, Player& player);
	static void SetInputMorpion(Grid& grid, Player& player, const int& input);
	static void SetInputCellMorpion(Grid& grid, Player& player, const int& input);

	static void InputPlayerPuissance4(Grid& grid, Player& player);
	static void SetInputPuissance4(Grid& grid, Player& player, const int& input);
	static void SetInputCellPuissance4(Grid& grid, Player& player, const int& input);

	static void InputPlayerOthello(Grid& grid, Player& player);
	static void SetInputOthello(Grid& grid, Player& player, const int& input);
	static void SetInputCellOthello(Grid& grid, Player& player, const int& input);

	static void InputBotPlayerMorpion(Grid& grid, Player& player);
	static void InputBotPlayerMPuissance4(Grid& grid, Player& player);
	static void InputBotPlayerOthello(Grid& grid, Player& player);

	static int BotRandomInputGeneratorMorpion(Grid& grid);
	static int BotRandomInputGeneratorPuissance4(Grid& grid);

	static bool IsNumericInput(const int& input);
	static int GetNumericInput();
	static string GetStringInput();

	static bool IsInputValidMorpion(const int& input);
	static bool IsInputValidPuissance4(const int& input);
	static bool IsInputValidGameModes(const int& input);

	static string InputGameChoice();
	static int InputGameMode();

	static void InputPlayersNames(Player& player1, Player& player2);
	static void InputPlayer1Name(Player& player1);
	static void InputPlayer2Name(Player& player2);

private:

};

#endif