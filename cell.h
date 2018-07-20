#ifndef _CELL_H_
#define _CELL_H_

class Info;
#include "subject.h"
#include "observer.h"
class Character;
//class Item;

enum class CellType { Floor, Passage, Door, Stairs };

class Cell: public Observer, public Subject {
	CellType type;
    unsigned int row;
    unsigned int col;
	Character *myChar = nullptr;
	//Item *myItem = nullptr;
public:
    Info getInfo();
	Cell(CellType type, unsigned int row, unsigned int col);
	CellType getType() const;
	//bool addItem(Item *i);
	bool addChar(Character *c);
	bool moveChar(int dir);
	void notify(Subject &from) override;
	//void notifyDisplay()
};

#endif
