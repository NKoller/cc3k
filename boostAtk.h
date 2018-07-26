#ifndef _BOOSTATK_H_
#define _BOOSTATK_H_

#include "potion.h"

class BoostAtk: public Potion {
		static bool used;
		void getUsed(Player &user) override;

	public:
		BoostAtk();
		static bool hasBeenUsed();
		std::string getDesc() const override;
};

#endif
