#ifndef _MERCHANT_H_
#define _MERCHANT_H_

#include "character.h"

class Merchant: public Character {
		static bool hostile;
		double generalAttack(Character &defender) override;

	public:
		Merchant();
		~Merchant();
		int defend(Character &attacker) override;
		void checkIfDead() override;
};

#endif
