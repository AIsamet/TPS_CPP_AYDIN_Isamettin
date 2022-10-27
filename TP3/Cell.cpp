#include "Cell.h"
#include <string>

int Cell::ID = 1;

Cell::Cell() {
	coordonneX = 0;
	coordonneY = 0;
	owner = 0;
	id = Cell::ID++;
}

int Cell::GetCoordonneX() {
	return coordonneX;
}

int Cell::GetCoordonneY() {
	return coordonneY;
}

int Cell::GetOwner(){
	return owner;
}

void Cell::setOwner(int i) {
	owner = i;
}

string Cell::DisplayCell() {
	string str = " ";
	if (owner == 0) {
		str = to_string(id);
	}
	else if (owner == 1) {
		str = "X";
	}
	else if (owner == 2) {
		str = "O";
	}
	return str;
}
