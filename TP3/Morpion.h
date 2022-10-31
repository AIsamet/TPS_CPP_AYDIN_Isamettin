#ifndef Morpion_h
#define Morpion_h

#include "Game.h"

class Morpion : public Game
{

public:
	Morpion();
	Morpion(string player1Name, string player2Name);

	inline Player GetPlayer1() const { return player1; }
	inline Player GetPlayer2() const { return player2; }

	void InitGrid(const int& line, const int& column) override;
	Cell& GetCellPositionFromId(const int& idCell);
	void DisplayPlate() const override;
	void InputPlayer(Player player) override;
	void StartGame() override;
	bool CheckEquality() const override;
	bool CheckWin(const Player& player) const override;
	bool CheckWinByLine(const Player& player) const override;
	bool CheckWinByColumn(const Player& player) const override;
	bool CheckWinByDiagonal(const Player& player) const override;

private:
	vector<vector<Cell> > gameGrid;
	Player player1;
	Player player2;
};

#endif