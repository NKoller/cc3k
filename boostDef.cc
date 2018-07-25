#include "boostDef.h"

bool BoostDef::used = false;

BoostDef::BoostDef():
		Potion{Stats{0, 0, 5, 0}, "BD, which boosts Def by 5"} {}

		bool BoostDef::hasBeenUsed() {
				return BoostDef::used;
		}

void BoostDef::getUsed(Player &user) {
		user.use(*this);
		BoostDef::used = true;
}

std::string BoostDef::getDesc() const {
		if (BoostDef::used) return desc;
		else return "";
}
