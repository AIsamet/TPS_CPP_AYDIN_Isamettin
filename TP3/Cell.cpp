#include "Cell.h"

Cell::Cell(const int& Line, const int& Column, const int& Owner) {
	line = Line;
	column = Column;
	owner = Owner;
}

Cell::Cell() {
	line = 0;
	column = 0;
	owner = 0;
}