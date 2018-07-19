#include "cell.h"
#include "info.h"

Cell::Cell(CellType type, unsigned int row, unsigned int col):
		Observer{},
		Subject{},
		type{type}, row{row}, col{col} {}

void Cell::notify(Subject &from) {
	/*just for testing:
	if (type == CellType::Floor) {
		std::cout << "floor" << std::endl;
	} else if (type == CellType::Passage) {
		std::cout << "passage" << std::endl;
	} else if (type == CellType::Door) {
		std::cout << "door" << std::endl;
	} else {
		std::cout << "stairs" << std::endl;
	}*/
}

CellType Cell::getType() const {
	return type;
}

Info Cell::getInfo(){
    char itemName;
    char characterName;
    if (myItem == nullptr){
        itemName = 0;
    } else{
       // itemName = myItem->getName();
    }
    if (myChar == nullptr){
        characterName = 0;
    } else{
       // characterName = myChar->getName();
    }
    return Info {type, itemName, characterName, row, col};
}
