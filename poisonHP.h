#ifndef _POISONHP_H_
#define _POISONHP_H_

#include "potion.h"

class PoisonHP: public Potion {
		static bool used;

	public:
		PoisonHP();
		bool hasBeenUsed();
		void getUsed(Player &user) override;
		std::string getDesc() const override;
		Stats reverse() const;
};

#endif
