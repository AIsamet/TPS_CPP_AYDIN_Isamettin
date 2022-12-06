#ifndef Morpion_h
#define Morpion_h

#include "Game.h"

class Morpion : public Game
{

public:
	Morpion();
	Morpion(string player1Name, string player2Name);
		
	Player PlayRound() override;
	void StartGame() override;
	
	bool CheckEquality() const override;
	bool CheckWin(const Player& player) const override;
	bool CheckWinByLine(const Player& player) const override;
	bool CheckWinByColumn(const Player& player) const override;
	bool CheckWinByDiagonal(const Player& player) const override;

private:

};

#endif