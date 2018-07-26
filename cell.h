#ifndef _CELL_H_
#define _CELL_H_

#include "subject.h"
#include "observer.h"
#include <string>

struct Info;
class Character;
class Item;

enum class CellType { Floor, Passage, Door, Stairs };

class Cell: public Observer, public Subject {
		CellType type;
		unsigned int row;
		unsigned int col;
		bool hasPlayer = false;
		Character *myChar = nullptr;
		Item *myItem = nullptr;
		int directionTo(unsigned int r, unsigned int c) const;
		char otherName = 0;
		int otherHP = -1;
		int dmgDealt = -1;
		int dirTo = -1;
		std::string descrip = "";

	public:
		int playerDir = -1;
		Character* getChar() const;
		bool processedThisTurn = false;
		bool frozen = false;
		Info getInfo();
		Cell(CellType type, unsigned int row, unsigned int col);
		CellType getType() const;
		void makeStairs();
		bool addItem(Item *i);
		bool addChar(Character *c, bool isPlayer = false);
		bool moveChar(int dir);
		void notify(Subject &from) override;
		void charAttack(int dir);
		void charDefend(Character &attacker, Cell &attacking_cell);
		void charUse(int dir);
		void itemGetUsed(Character &user);
		~Cell();
};

#endif
