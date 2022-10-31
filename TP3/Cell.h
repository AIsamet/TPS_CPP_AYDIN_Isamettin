#ifndef Cell_h
#define Cell_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cell
{
	
public:
	Cell();

	inline int GetIdCell() const { return this->idCell; }
	inline int GetOwner() const { return this->owner; }
	inline void SetOwner(const int& NewOwner) { this->owner = NewOwner; }
	inline void static SetIdStatic(const int& NewIdStatic) { idStatic = NewIdStatic; }

	string DisplayCellMorpion() const;
	string DisplayCellPuissance4() const;
	

private:
	static int idStatic;
	int idCell;
	//0 = free; 1 = player 1; 2 = player 2;
	int owner;
};

#endif