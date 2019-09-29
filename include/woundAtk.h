#ifndef _WOUNDATK_H_
#define _WOUNDATK_H_

#include "potion.h"

class WoundAtk: public Potion {
		static bool used;
		void getUsed(Player &user) override;

	public:
		WoundAtk();
		static bool hasBeenUsed();
		std::string getDesc() const override;
};

#endif
