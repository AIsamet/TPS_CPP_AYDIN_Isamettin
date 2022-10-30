#include "Cell.h"

int Cell::ID = 1;

Cell::Cell() {
	owner = 0;
	id = Cell::ID++;
}

int Cell::GetId() const {
	return id;
}

int Cell::GetOwner() const{
	return owner;
}

void Cell::SetOwner(const int& NewOwner) {
	owner = NewOwner;
}

string Cell::DisplayCellMorpion() const{
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
