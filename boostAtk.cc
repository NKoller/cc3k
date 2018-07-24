#include "boostAtk.h"

bool BoostAtk::used = false;

BoostAtk::BoostAtk(): Potion{Stats{0, 5, 0, 0}} {}

bool BoostAtk::hasBeenUsed() {
	return BoostAtk::used;
}

void BoostAtk::getUsed(Player &user) {
	user.use(*this);
	BoostAtk::used = true;
}
