#include "cell.h"
#include "info.h"
#include "character.h"
#include <assert.h> //REMOVE
#include <iostream> //REMOVE

Cell::Cell(CellType type, unsigned int row, unsigned int col):
		Observer{},
		Subject{},
		type{type}, row{row}, col{col} {}

int Cell::directionTo(unsigned int r, unsigned int c) const {
	assert(!(r == row && c == col));
	if (r < row) {
		if (c < col) return 0;
		else if (c == col) return 1;
		else return 2;
	} else if (r == row) {
		if (c < col) return 3;
		else return 4;
	} else {
		if (c < col) return 5;
		else if (c == col) return 6;
		else return 7;
	}
}

void Cell::notify(Subject &from) {
	if (from.getState() == State::PlayerHere) {
		Info in = static_cast<Cell *>(&from)->getInfo(); // really bad
		playerDir = directionTo(in.row, in.col);
	} else if (from.getState() == State::PlayerGone) {
		playerDir = -1;
	}
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

bool Cell::addChar(Character *c, bool isPlayer) {
	if (myChar) return false;
	myChar = c;
	if (isPlayer) {
		setState(State::PlayerHere);
		hasPlayer = true;
	}
	else {
		setState(State::CharacterMoved);
	}
	notifyObservers();
	return true;
}

bool Cell::moveChar(int dir) {
	assert(myChar);
	if (!observers[dir] || !myChar->moves()) return false;

	bool added = static_cast<Cell *>(observers[dir])->addChar(myChar, hasPlayer);
	if (added) {
		myChar = nullptr;
		if (hasPlayer) setState(State::CharacterMoved);
		else setState(State::PlayerGone);
		hasPlayer = false;
		notifyObservers();
		return true;
	} else {
		return false;
	}
}

void Cell::charAttack(int dir) {
	static_cast<Cell *>(observers[dir])->charDefend(*myChar);
}

void Cell::charDefend(Character &attacker) {
	myChar->defend(attacker);
}
