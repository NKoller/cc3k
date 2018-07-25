#ifndef _POTION_H_
#define _POTION_H_

#include "item.h"

class Potion: public Item {
	public:
		Potion(Stats effect, std::string desc);
		virtual Stats reverse() const;
};

#endif
