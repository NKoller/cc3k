#ifndef _RESTOREHP_H_
#define _RESTOREHP_H_

#include "potion.h"

class RestoreHP: public Potion {
		static bool used;
		void getUsed(Player &user) override;

	public:
		RestoreHP();
		static bool hasBeenUsed();
		std::string getDesc() const override;
		Stats reverse() const;
};

#endif
