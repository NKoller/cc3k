#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "character.h"

class Human: public Character {
	public:
		Human();
		~Human();
		void checkIfDead() override;
		int defend(Character &attacker) override;
};

#endif
