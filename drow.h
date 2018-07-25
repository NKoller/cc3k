#ifndef _DROW_H_
#define _DROW_H_

#include "player.h"

class Drow: public Player {
	public:
		int defend(Character &attacker) override;
		void use(Potion &p) override;
		Drow();
		~Drow();
};

#endif
