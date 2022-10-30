#ifndef Puissance4_h
#define Puissance4_h

#include "Game.h"

class Puissance4 : public Game
{

public:
	Puissance4();
	Puissance4(string player1Name, string player2Name);

	Player GetPlayer1() const;
	Player GetPlayer2() const;

	void InitGrid(const int& line, const int& column) override;
	Cell& GetCellPositionFromId(const int& idCell) override;
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