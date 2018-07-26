#ifndef _BOOSTDEF_H_
#define _BOOSTDEF_H_

#include "potion.h"

class BoostDef: public Potion {
		static bool used;
		void getUsed(Player &user) override;

	public:
		BoostDef();
		static bool hasBeenUsed();
		std::string getDesc() const override;
};

#endif
