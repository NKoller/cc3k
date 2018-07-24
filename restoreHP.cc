#include "restoreHP.h"

bool RestoreHP::used = false;

RestoreHP::RestoreHP():
	Potion{Stats{10, 0, 0, 0}, "RH, which restores 10 HP"} {}
  
bool RestoreHP::hasBeenUsed() {
	return RestoreHP::used;
}

void RestoreHP::getUsed(Player &user) {
	user.use(*this);
	RestoreHP::used = true;
}

std::string RestoreHP::getDescription() const {
	if (RestoreHP::used) return description;
	else return "";
}
