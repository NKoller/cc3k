#ifndef _HALFLING_H_
#define _HALFLING_H_

#include "character.h"

class Halfling: public Character {
	public:
		Halfling();
		~Halfling();
		int defend(Character &attacker) override;
};

#endif
