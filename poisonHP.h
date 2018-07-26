#ifndef _POISONHP_H_
#define _POISONHP_H_

#include "potion.h"

class PoisonHP: public Potion {
		static bool used;
		void getUsed(Player &user) override;

	public:
		PoisonHP();
		bool hasBeenUsed();
		std::string getDesc() const override;
		Stats reverse() const;
};

#endif
