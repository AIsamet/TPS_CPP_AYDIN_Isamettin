#ifndef Input_h
#define Input_h

#include "Game.h"

class Input
{

public:
	Input();

	static void InputMorpion(Grid& grid, Player player);
	static void InputPuissance4(Grid& grid, Player player);
	static void InputPlayerMorpion(Grid& grid, Player player);
	static void InputPlayerPuissance4(Grid &grid, Player player);
	static void InputBotPlayerMorpion(Grid& grid, Player player);
	static void InputBotPlayerMPuissance4(Grid& grid, Player player);
	static int BotRandomInputGeneratorMorpion(Grid& grid, Player player);
	static int BotRandomInputGeneratorPuissance4(Grid& grid, Player player);
	
	static int InputGameType();
	static string InputPlayersName();
	
private:
	
};


#endif