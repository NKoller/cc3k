#include "cell.h"

Cell::Cell(CellType type):
		Observer{},
		Subject{},
		type{type} {}

void Cell::notify(Subject &from) {}

CellType Cell::getType() const {
	return type;
}
