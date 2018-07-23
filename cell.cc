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
		//if (myChar) std::cout << "notified by player at " << in.row << " " << in.col;
		playerDir = directionTo(in.row, in.col);
		//if (myChar) std::cout << " direction " << playerDir << std::endl;
	} else if (from.getState() == State::PlayerGone) {
		playerDir = -1;
	} else if (from.getState() == State::CharacterDied) {
		delete myChar;
		myChar = nullptr;
		setState(State::CharacterMoved); // maybe need a new state
		notifyObservers();
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
	if (!isPlayer && type != CellType::Floor) return false;

	myChar = c;
	c->attach(this);
	if (isPlayer) {
		//std::cout << row << " playerhere " << col << std::endl;
		setState(State::PlayerHere);
		hasPlayer = true;
	}
	else {
		setState(State::CharacterMoved);
	}
	notifyObservers();
	if (!isPlayer) processedThisTurn = true;
	return true;
}

bool Cell::moveChar(int dir) {
	if (!myChar || processedThisTurn) return true;
	//std::cout << row << " " << col << " " << hasPlayer << std::endl;
	if (playerDir != -1) {
		//std::cout << row << " " << col << " " << playerDir << std::endl;
		//std::cout << "HIYAH!" << std::endl;
		charAttack(playerDir);
		return true;
	}

	if (!observers[dir]) return false;
	if (!myChar->moves()) return true;

	if (hasPlayer) {
		setState(State::PlayerGone);
		notifyObservers();
	}
	bool added = static_cast<Cell *>(observers[dir])->addChar(myChar, hasPlayer); // this is terrible
	if (added) {
		myChar = nullptr;
		hasPlayer = false;
		setState(State::CharacterMoved);
		notifyObservers();
		return true;
	} else {
		if (hasPlayer) setState(State::PlayerHere);
		notifyObservers();
		return false;
	}
}

void Cell::charAttack(int dir) {
	static_cast<Cell *>(observers[dir])->charDefend(*myChar);
	//std::cout << "attempting to attack " << dir << std::endl;
}

void Cell::charDefend(Character &attacker) {
	//std::cout << "defending!" << std::endl;
	if (myChar) myChar->defend(attacker);
}
