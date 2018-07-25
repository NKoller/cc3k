#ifndef _BOOSTDEF_H_
#define _BOOSTDEF_H_

#include "potion.h"

class BoostDef: public Potion {
		static bool used;
	public:
		BoostDef();
		static bool hasBeenUsed();
		void getUsed(Player &user) override;
		std::string getDesc() const override;
};

#endif
