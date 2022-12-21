#ifndef Othello_h
#define Othello_h

#include "Game.h"

// Classe du jeu de othello
class Othello : public Game
{
public:
	/**
	 * Constructeur
	**/
	Othello();

	/**
	 * Methodes
	**/
	Player PlayRound() override;
	void StartGame() override;
	void EndGame(const Player& PotentialWinner);

	bool CheckEquality() const override;
	bool CheckWin(const Player& player) const override;
	bool CheckWinByLine(const Player& player) const override;
	bool CheckWinByColumn(const Player& player) const override;
	bool CheckWinByDiagonal(const Player& player) const override;

	void FlipCellsByLine(const Player& player);
	void FlipCellsByColumn(const Player& player);
	void FlipCellsByDiagonal(const Player& player);

private:

};

#endif

