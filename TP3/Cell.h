#ifndef Cell_h
#define Cell_h

#include "Game.h"

class Cell
{
public:
	Cell();
	int GetOwner();
	int GetCoordonneX();
	int GetCoordonneY();
	string DisplayCell();
	
	void setOwner(int i);

	
private:
	static int ID;
	int id;
	int coordonneX;
	int coordonneY;
	//0 = free; 1 = player 1; 2 = player 2;
	int owner;
};

#endif