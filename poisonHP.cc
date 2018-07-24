#include "poisonHP.h"

bool PoisonHP::used = false;
  
PoisonHP::PoisonHP(): Potion{Stats{-10, 0, 0, 0}} {}

bool PoisonHP::hasBeenUsed() {
	return PoisonHP::used;
}

void PoisonHP::getUsed(Player &user) {
	user.use(*this);
	PoisonHP::used = true;
}
