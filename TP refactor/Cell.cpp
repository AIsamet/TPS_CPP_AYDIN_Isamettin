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
		str = "\033[1;31mX\033[0m";
	}
	else if (owner == 2) {
		str = "\033[1;32mO\033[0m";
	}
	return str;
}

string Cell::DisplayCellPuissance4() const {
	string str = " ";
	if (owner == 0) {
		str = " ";
	}
	else if (owner == 1) {
		str = "\033[1;31mO\033[0m";
	}
	else if (owner == 2) {
		str = "\033[1;32mO\033[0m";
	}
	return str;
}
