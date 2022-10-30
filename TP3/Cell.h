#ifndef Cell_h
#define Cell_h

#include <iostream>
#include <vector>
using namespace std;

class Cell
{
public:
	Cell();
	int GetOwner();
	void SetOwner(int NewOwner);
	string DisplayCell();
	
private:
	static int ID;
	int id;
	//0 = free; 1 = player 1; 2 = player 2;
	int owner;
};

#endif