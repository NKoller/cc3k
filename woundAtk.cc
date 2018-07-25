#include "woundAtk.h"

bool WoundAtk::used = false;

WoundAtk::WoundAtk():
		Potion{Stats{0, -5, 0, 0}, "WA, which decreases Atk by 5"} {}

		bool WoundAtk::hasBeenUsed() {
				return WoundAtk::used;
		}

void WoundAtk::getUsed(Player &user) {
		user.use(*this);
		WoundAtk::used = true;
}

std::string WoundAtk::getDesc() const {
		if (WoundAtk::used) return desc;
		else return "";
}
