#ifndef Puissance4_h
#define Puissance4_h

#include "Game.h"

class Puissance4 : public Game
{

public:
	Puissance4();
	Puissance4(string player1Name, string player2Name);
		
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