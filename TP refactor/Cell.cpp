#include "Cell.h"

/**
 * @brief   Construit une nouvelle case
 * @params  IdCell : identifiant de la case
**/
Cell::Cell(const int& IdCell) {
	idCell = IdCell;
	owner = 0;
}