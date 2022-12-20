#ifndef Checks_h
#define Checks_h

#include "Game.h"

// Classe fonctionnelle gerant toutes les sorties
class Checks
{
public:
	//Inputs Checks
	static bool IsNumericInput(const int& input);
	static bool IsInputByCellValid(const int& input, const int& maxInput);
	static bool IsInputByColumnValid(const int& input, const int& maxInput);

	static bool IsOthelloCellPlayable(const Grid& grid, const Player& player, const int& input);
	static bool IsOthelloCellFlipable(const Grid& grid, const Player& player, const int& input, const int& cellIdToCheck);

	static bool IsInputValidGameModes(const int& input);
	
	//Players Checks
	static bool IsPlayerBot(const Player& player);

	//Cell Checks ?
	//IsCellFree?

private:

};

#endif