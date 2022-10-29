#include "Game.h"
#include <string>

int main() {
	
	//Morpion newMorpion;
	//
	//newMorpion.GetGrid().DisplayGrid();
	//
	//newMorpion.GetGrid().GetCell(0, 0).setOwner(1);
	//
	//cout << "prop : " << newMorpion.GetGrid().GetCell(0, 0).GetOwner();
	
	Grid newGrid(3,3);
	newGrid.DisplayGrid();
	cout << newGrid.GetCell(0, 0).GetOwner();
	newGrid.GetCell(0, 0).setOwner(2);
	cout << newGrid.GetCell(0, 0).GetOwner();

	return 0;
}
