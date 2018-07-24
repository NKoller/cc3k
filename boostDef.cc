#include "boostDef.h"

bool BoostDef::used = false;

BoostDef::BoostDef(): Potion{Stats{0, 0, 5, 0}} {}

bool BoostDef::hasBeenUsed() {
	return BoostDef::used;
}

void BoostDef::getUsed(Player &user) {
	user.use(*this);
	BoostDef::used = true;
}
