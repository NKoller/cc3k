#ifndef _CELL_H_
#define _CELL_H_

#include "subject.h"
#include "observer.h"

enum class CellType { Floor, Passage, Door, Stairs };

class Cell: public Observer, public Subject {
	CellType type;
	//Character *myChar;
	//Item *myItem;
public:
	Cell(CellType type);
	//bool addItem(Item *);
	//bool addChar(Character *);
	//bool moveChar(Direction);
	void notify(Subject &from) override;
	//void notifyDisplay()
}

#endif
