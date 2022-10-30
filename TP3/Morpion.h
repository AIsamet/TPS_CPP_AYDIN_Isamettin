#ifndef Morpion_h
#define Morpion_h

#include "Cell.h"
#include "Player.h"

class Morpion
{

public:
	Morpion();
	Morpion(string player1Name, string player2Name);

	Player GetPlayer1() const;
	Player GetPlayer2() const;

	void InitGrid(const int& line, const int& column);
	Cell& GetCellPositionFromId(const int& idCell);
	void DisplayPlate() const;
	void InputPlayer(Player player);
	void StartGame();
	bool CheckEquality() const;
	bool CheckWin(const Player& player) const;
	bool CheckWinByLine(const Player& player) const;
	bool CheckWinByColumn(const Player& player) const;
	bool CheckWinByDiagonal(const Player& player) const;

private:
	vector<vector<Cell> > gameGrid;
	Player player1;
	Player player2;
};

#endif