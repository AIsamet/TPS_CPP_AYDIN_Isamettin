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

	static void InputPlayerMorpion(Grid& grid, Player& player);
	static void InputPlayerPuissance4(Grid& grid, Player& player);

	static void InputBotPlayerMorpion(Grid& grid, Player& player);
	static void InputBotPlayerMPuissance4(Grid& grid, Player& player);

	static int BotRandomInputGeneratorMorpion(Grid& grid);
	static int BotRandomInputGeneratorPuissance4(Grid& grid);

	static string InputGameChoice();
	static int InputGameMode();
	static string InputPlayersNames();

private:

};

#endif