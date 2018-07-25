#include "woundDef.h"

bool WoundDef::used = false;

WoundDef::WoundDef():
		Potion{Stats{0, 0, -5, 0}, "WD, which decreases Def by 5"} {}

		bool WoundDef::hasBeenUsed() {
				return WoundDef::used;
		}

void WoundDef::getUsed(Player &user) {
		user.use(*this);
		WoundDef::used = true;
}

std::string WoundDef::getDesc() const {
		if (WoundDef::used) return desc;
		else return "";
}
