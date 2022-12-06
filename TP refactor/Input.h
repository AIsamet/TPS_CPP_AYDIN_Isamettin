#ifndef Input_h
#define Input_h

#include "Morpion.h"
#include "Puissance4.h"

class Input
{

public:
	Input();

	static void InputPlayerMorpion(Grid& grid, Player player);
	static void InputPlayerPuissance4(Grid &grid, Player player);
	static void InputBotPlayerMorpion(Grid& grid, Player player);
	static void InputBotPlayerMPuissance4(Grid& grid, Player player);
	static int InputGameType();
	static string InputPlayersName();

	static int BotRandomInputGeneratorMorpion(Grid& grid, Player player);
	static int BotRandomInputGeneratorPuissance4(Grid& grid, Player player);



private:

};


#endif