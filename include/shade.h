#ifndef _SHADE_H_
#define _SHADE_H_

#include "player.h"

class Shade: public Player {
	public:
		int defend(Character &attacker) override;
		int getScore() const override; 
		Shade();
		~Shade();
};

#endif
