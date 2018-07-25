#ifndef _INFO_H_
#define _INFO_H_

#include "cell.h"
#include <string.h>

struct Info {
		CellType type;
		char itemName;
		char characterName;
		char otherCharName;
		double otherCharHP;
		double damageDealt;
		int direction;
		std::string descrip;
		unsigned int row;
		unsigned int col;
};

#endif
