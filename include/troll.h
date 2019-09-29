#ifndef _TROLL_H_
#define _TROLL_H_

#include "player.h"

class Troll: public Player {
	public:
		int defend(Character &attacker) override;
		void finishTurn() override;
		Troll();
		~Troll();
};

#endif
