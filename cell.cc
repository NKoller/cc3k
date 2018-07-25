#include "cell.h"
#include "info.h"
#include "character.h"
#include "item.h"
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

Character* Cell::getChar()const{
    return myChar;
}

void Cell::notify(Subject &from) {
	if (from.getState() == State::PlayerHere) {
		Info in = static_cast<Cell *>(&from)->getInfo(); // really bad
		//if (myChar) std::cout << "notified by player at " << in.row << " " << in.col;
		playerDir = directionTo(in.row, in.col);
		//if (myChar) std::cout << " direction " << playerDir << std::endl;
        if (myItem){
            setState(State::DeclareItem);
            notifyObservers();
        }
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

void Cell::makeStairs() {
	type = CellType::Stairs;
	processedThisTurn = true;
	setState(State::CharacterMoved); // maybe rename
	notifyObservers();
}

Info Cell::getInfo(){
	char characterName;
    char itemName = 0;
    if (myItem == nullptr){
        itemName = 0;
    } else{
		itemName = myItem->getName();
        descrip = myItem->getDesc();
    }
    if (myChar == nullptr){
        characterName = 0;
    } else{
        characterName = myChar->getName();
    }
    return Info {type, itemName, characterName, otherName, otherHP, dmgDealt, dirTo, descrip, row, col};
}

bool Cell::addItem(Item *i) {
	if (myItem) return false;
	myItem = i;
	setState(State::CharacterMoved); // not really proper
	notifyObservers();
	processedThisTurn = true;
	return true;
}

bool Cell::addChar(Character *c, bool isPlayer) {
    if (c){
	if (myChar || myItem) return false;
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
    if (!hasPlayer && frozen) return true;

	if (!observers[dir]) return false;
	if (!myChar->moves()) return true;

	if (hasPlayer) {
		setState(State::PlayerGone);
		notifyObservers();
	}
	bool added = static_cast<Cell *>(observers[dir])->addChar(myChar, hasPlayer); // this is terrible
	if (added) {
		myChar = nullptr;
        if (hasPlayer){
            dirTo = dir;
            setState(State::PlayerMoved);
            notifyObservers();
        }
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
    if (observers[dir]){
	static_cast<Cell *>(observers[dir])->charDefend(*myChar, *this);
    }
	//std::cout << "attempting to attack " << dir << std::endl;
}

void Cell::charDefend(Character &attacker, Cell &attacking_cell) {
	//std::cout << "defending!" << std::endl;
	if (myChar && type != CellType::Stairs){
        int dmg = myChar->defend(attacker);
		if (dmg == Character::MISSED) {
            dmgDealt = dmg;
            otherName = attacker.getName();
            otherHP = myChar->getStats().HP;
            setState(State::GotAttacked);
            notifyObservers();
			return;
			// notify TD that it missed?
		} else if (dmg == Character::NO_ATTACK) {
			int temp = attacking_cell.playerDir;
			attacking_cell.playerDir = -1;
			attacking_cell.processedThisTurn = false;
			int counter;
			int dir;
			do {
				dir = rand() % 8;
				++counter;
			} while (!attacking_cell.moveChar(dir) && counter < 100);
			attacking_cell.playerDir = temp;
		} else {
    	    otherName = attacker.getName();
	        otherHP = myChar->getStats().HP;
        	dmgDealt = dmg;
    	    setState(State::GotAttacked);
	        notifyObservers();
        	std::cout << "here lol" << std::endl;
        	myChar->checkIfDead();
		}
    }
}

void Cell::charUse(int dir) {
    if (observers[dir]){
	static_cast<Cell *>(observers[dir])->itemGetUsed(*myChar);
    }
}

void Cell::itemGetUsed(Character &user) {
	if (myItem) myItem->getUsed(user);
	//delete myItem; player will delete it
    setState(State::ItemUsed);
    notifyObservers();
	myItem = nullptr;
	setState(State::CharacterMoved); // not really proper
	notifyObservers();
}
Cell::~Cell(){
    if (!hasPlayer){
    delete myChar;
    }
    delete myItem;
}
