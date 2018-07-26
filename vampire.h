#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

#include "player.h"

class Vampire: public Player {
		double generalAttack(Character &defender) override;

	public:
		int defend(Character &attacker) override;;
		double attack(Dwarf &defender) override;
		Vampire();
		~Vampire();
};

#endif
