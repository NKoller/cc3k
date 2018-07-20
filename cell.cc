#include "cell.h"
#include "info.h"
#include "character.h"
#include <assert.h> //REMOVE
#include <iostream> //REMOVE

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
	char characterName;
    char itemName = 0;
	/*
    if (myItem == nullptr){
        itemName = 0;
    } else{
		itemName = '?';
       // itemName = myItem->getName();
    }*/
    if (myChar == nullptr){
        characterName = 0;
    } else{
        characterName = myChar->getName();
    }
    return Info {type, itemName, characterName, row, col};
}

bool Cell::addChar(Character *c) {
	if (myChar) return false;
	myChar = c;
	setState(State::CharacterMoved);
	notifyObservers();
	return true;
}

bool Cell::moveChar(int dir) {
	assert(myChar);
	if (!observers[dir]) return false;

	bool added = static_cast<Cell *>(observers[dir])->addChar(myChar);
	if (added) {
		myChar = nullptr;
		setState(State::CharacterMoved);
		notifyObservers();
		return true;
	} else {
		return false;
	}
}
