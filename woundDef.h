#ifndef _WOUNDDEF_H_
#define _WOUNDDEF_H_

#include "potion.h"

class WoundDef: public Potion {
		static bool used;
		void getUsed(Player &user) override;

	public:
		WoundDef();
		static bool hasBeenUsed();
		std::string getDesc() const override;
};

#endif
