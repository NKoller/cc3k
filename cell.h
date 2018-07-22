#ifndef _CELL_H_
#define _CELL_H_

struct Info;
#include "subject.h"
#include "observer.h"
class Character;
//class Item;

enum class CellType { Floor, Passage, Door, Stairs };

class Cell: public Observer, public Subject {
	CellType type;
    unsigned int row;
    unsigned int col;
	bool hasPlayer = false;
	int playerDir = -1;
	Character *myChar = nullptr;
	//Item *myItem = nullptr;
	int directionTo(unsigned int r, unsigned int c) const;
public:
	bool movedThisTurn = false;
    Info getInfo();
	Cell(CellType type, unsigned int row, unsigned int col);
	CellType getType() const;
	//bool addItem(Item *i);
	bool addChar(Character *c, bool isPlayer = false);
	bool moveChar(int dir);
	void notify(Subject &from) override;
	//void notifyDisplay()
	void charAttack(int dir);
	void charDefend(Character &attacker);
};

#endif
