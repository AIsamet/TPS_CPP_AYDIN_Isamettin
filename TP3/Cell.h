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

	int GetId() const;
	int GetOwner() const;
	void SetOwner(const int& NewOwner);

	string DisplayCellMorpion() const;
	string DisplayCellPuissance4() const;

private:
	static int ID;
	int id;
	//0 = free; 1 = player 1; 2 = player 2;
	int owner;
};

#endif