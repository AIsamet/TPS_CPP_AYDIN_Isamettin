#ifndef Game_h
#define Game_h

#include "Player.h"
#include "Cell.h"

class Game
{
public:
	Game();

	virtual void InitGrid(const int& line, const int& column) = 0;
	virtual Cell& GetCellPositionFromId(const int& idCell) = 0;
	virtual void DisplayPlate() const = 0;
	virtual void InputPlayer(Player player) = 0;
	virtual void StartGame() = 0;
	virtual bool CheckEquality() const = 0;
	virtual bool CheckWin(const Player& player) const = 0;
	virtual bool CheckWinByLine(const Player& player) const = 0;
	virtual bool CheckWinByColumn(const Player& player) const = 0;
	virtual bool CheckWinByDiagonal(const Player& player) const = 0;
	

private:

};

#endif