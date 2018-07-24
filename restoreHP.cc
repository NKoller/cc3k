#include "restoreHP.h"

bool RestoreHP::used = false;

RestoreHP::RestoreHP(): Potion{Stats{10, 0, 0, 0}} {}
  
bool RestoreHP::hasBeenUsed() {
	return RestoreHP::used;
}

void RestoreHP::getUsed(Player &user) {
	user.use(*this);
	RestoreHP::used = true;
}
