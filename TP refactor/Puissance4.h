#ifndef Puissance4_h
#define Puissance4_h

#include "Game.h"

// Classe du jeu de puissance 4
class Puissance4 : public Game
{
public:
	/**
	 * Constructeur
	**/
	Puissance4();

	/**
	 * Methodes
	**/
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