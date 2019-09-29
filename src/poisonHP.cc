#include "poisonHP.h"

bool PoisonHP::used = false;

PoisonHP::PoisonHP():
		Potion{Stats{-10, 0, 0, 0}, "PH, which reduces HP by 10"} {}

bool PoisonHP::hasBeenUsed() {
		return PoisonHP::used;
}

void PoisonHP::getUsed(Player &user) {
		user.use(*this);
		PoisonHP::used = true;
}

std::string PoisonHP::getDesc() const {
		if (PoisonHP::used) return desc;
		else return "";
}

Stats PoisonHP::reverse() const {
		return Stats{0, 0, 0, 0};
}
