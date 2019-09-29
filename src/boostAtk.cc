#include "boostAtk.h"

bool BoostAtk::used = false;

BoostAtk::BoostAtk():
		Potion{Stats{0, 5, 0, 0}, "BA, which boosts Atk by 5"} {}

		bool BoostAtk::hasBeenUsed() {
				return BoostAtk::used;
		}

void BoostAtk::getUsed(Player &user) {
		user.use(*this);
		BoostAtk::used = true;
}

std::string BoostAtk::getDesc() const {
		if (BoostAtk::used) return desc;
		else return "";
}
