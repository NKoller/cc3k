#include "cell.h"

Cell::Cell(CellType type):
		Observer{},
		Subject{},
		type{type} {}

void Cell::notify(Subject &from) {}

CellType Cell::getType() const {
	return type;
}

Info Cel::getInfo(){
    char itemName;
    char characterName;
    if (myItem == nullptr){
        itemName = 0;
    } else{
        itemName = myItem.getName();
    }
    if (myChar == nullptr){
        characterName = 0;
    } else{
        characterName = myChar.getName();
    }

}
