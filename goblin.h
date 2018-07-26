#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include "player.h"

class Goblin: public Player {
		double generalAttack(Character &defender);

	public:
		int defend(Character &attacker) override;
		Goblin();
		~Goblin();
};

#endif
