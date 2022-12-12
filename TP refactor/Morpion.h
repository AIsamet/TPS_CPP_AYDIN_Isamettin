#ifndef Morpion_h
#define Morpion_h

#include "Game.h"

// Classe du jeu de morpion
class Morpion : public Game
{
public:
	/**
	 * Constructeur
	**/
	Morpion();

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