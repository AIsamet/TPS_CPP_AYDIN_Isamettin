#include "Cell.h"

int Cell::idStatic = 1;

Cell::Cell() {
	owner = 0;
	idCell = Cell::idStatic++;
}

string Cell::DisplayCellMorpion() const{
	string str = " ";
	if (owner == 0) {
		str = to_string(idCell);
	}
	else if (owner == 1) {
		str = "X";
	}
	else if (owner == 2) {
		str = "O";
	}
	return str;
}

string Cell::DisplayCellPuissance4() const {
	string str = " ";
	if (owner == 0) {
		str = " ";
	}
	else if (owner == 1) {
		str = "X";
	}
	else if (owner == 2) {
		str = "O";
	}
	return str;
}
