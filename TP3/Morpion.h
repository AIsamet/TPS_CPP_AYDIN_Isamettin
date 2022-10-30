#ifndef Morpion_h
#define Morpion_h

#include "Cell.h"
#include "Player.h"

class Morpion
{
	
public:
	Morpion();
	Morpion(int i, int j);

	Cell& GetCell(int idCell);
	Player GetPlayer();
	
	void DisplayPlate();
	void InitGrid(int i, int j);
	void InputPlayer(Player player);
	void InitGame();
	bool CheckEquality();
	bool CheckWin(Player player);
	bool CheckWinByLine(Player player);
	bool CheckWinByColumn(Player player);
	bool CheckWinByDiagonal(Player player);

private:
	vector<vector<Cell> > gameGrid;
	Player player1;
	Player player2;

};

#endif